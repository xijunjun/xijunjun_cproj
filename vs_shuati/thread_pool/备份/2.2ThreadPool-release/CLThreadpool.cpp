#include "CLThreadPool.h"
#include <iostream>  
#include <Windows.h>  
using namespace std;

//在传入子线程指针时，需要考虑指针所指向对象的生存时间，假设传入局部变量的指针，局部变量销毁过后，子线程指向的内容将不确定
void CLApply::RunThreadFunction()
{
	initflag = 1;
	mWaitLock.Lock();//需要考虑主线程可能还没等子线程阻塞在这里，就已经发出了unlock的唤醒命令
	while (1)
	{
	//注意此处尽量不要在mSourceLock->Unlock();之前写代码，如果写要考虑主线程对公共变量（如公共互斥变量是否初始化完成）
		mWaitLock.Lock();//lock的含义是若当前锁可用，则获得锁，继续。如果当前锁不可用，则等待锁可用过后，并上锁,然后继续。
		if (mkillflag == 1 ){ break; }//注意要保证程序任务完成后再杀死
		Sleep(10);
		Task onetask = *((Task*)m_pContext);
		mSourceLock->Lock();
		cout << "thread" << thid << ":" << *(onetask.input)<< " ";
		(onetask.output).push_back(int(*(onetask.input))-32);
		mSourceLock->Unlock();

		isbusy = 0;
		sem_post(m_pmsem);//信号量加1
	}
	mWaitLock.Unlock();//注意！！mutex变量在释放之前一定要处于unlock（空闲状态），否则pthread_mutex_destroy函数将返回错误值
}

CLThreadPool::CLThreadPool(int num)//注意ThreadPool的构造函数需要一定的初始化时间
{
	
	mthnum = num;
	mpThread= new CLApply[num];
	for (int i = 0; i < num; i++)//注意此处对
	{
		(mpThread + i)->set_config(i, &mSourceLock,&m_pmsem);
	}
	waitInit();
	sem_init(&m_pmsem, 0, num);//等待线程初始化完成，阻塞，初始化信号量

}
CLThreadPool::~CLThreadPool()
{
     std::cout << "~CLThreadPool()" << std::endl;
	delete []mpThread ;
	int r = sem_destroy(&m_pmsem);
	if (r != 0)
	{
		throw "sem_destroy error";
	}
	//!!!sem_destroy
}
void CLThreadPool::waitInit()//等待所有线程初始化到initflag = 1的地方,否则将造成子线程还没初始化到设想的位置，主线程就开始addtask，参考《linux程序设计实践》3.5.9
{
	for (int i = 0; i < mthnum; i++)
	{
		while ((mpThread + i)->initflag == 0);
	}
}
void CLThreadPool::AddTask(void *pContext)
{
	//获得一个信号，就要分发一个task
	sem_wait(&m_pmsem);
	for (int i = 0; i < mthnum; i++)
	{
		if ((mpThread + i)->isbusy == 0 )
		{
			(mpThread + i)->SetData(pContext);
			break;
		}
	}
	
}
void CLThreadPool::killall()//注意杀死所有线程要保证子线程都已完成任务
{

	for (int i = 0; i < mthnum; i++)
	{
		while ((mpThread + i)->isbusy == 1);//一直等到线程变为空闲才将其杀死
		(mpThread + i)->killself();
		(mpThread + i)->WaitForDeath();
	}
}
