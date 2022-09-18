#include "CLThreadPool.h"
#include <iostream>  
#include <Windows.h>  
using namespace std;

class CLApply : public CLThread
{
public:
	//在传入子线程指针时，需要考虑指针所指向对象的生存时间，假设传入局部变量的指针，局部变量销毁过后，子线程指向的内容将不确定
	virtual void RunThreadFunction()
	{
		initflag = 1;
		mWaitLock.Lock();//需要考虑主线程可能还没等子线程阻塞在这里，就已经发出了unlock的唤醒命令
		while (1)
		{
		//注意此处尽量不要在mSourceLock->Unlock();之前写代码，如果写要考虑主线程对公共变量（如公共互斥变量是否初始化完成）
		 mWaitLock.Lock();//lock的含义是若当前锁可用，则获得锁，继续。如果当前锁不可用，则等待锁可用过后，并上锁,然后继续。
		 if (mkillflag == 1 && isbusy==0){ break; }//注意要保证程序任务完成后再杀死
		 Sleep(100);
		 Task onetask = *((Task*)m_pContext);
		 mSourceLock->Lock();
		 cout << "thread " << thid << ":" << *(onetask.input)<< endl;
		 (onetask.output).push_back(int(*(onetask.input))-32);
		 mSourceLock->Unlock();

		 //char onetask = *((char*)m_pContext);
		 //mSourceLock->Lock();
		 //cout << "thread " << thid << ":" << onetask << endl;
		 ////(onetask.output).push_back(int(*(onetask.input))-32);
		 //mSourceLock->Unlock();

		 isbusy = 0;
		}
	}

};
CLThreadPool::CLThreadPool(int num)//注意ThreadPool的构造函数需要一定的初始化时间
{
	mthnum = num;
	//cout << "num:" << num << endl;
	mpThread= new CLApply[num];
	for (int i = 0; i < num; i++)//注意此处对
	{
		(mpThread + i)->set_config(i, mSourceLock);
	}
	waitInit();
}
void CLThreadPool::waitInit()//等待所有线程初始化到initflag = 1的地方
{
	for (int i = 0; i < mthnum; i++)
	{
		while ((mpThread + i)->initflag == 0);
	}
}
void CLThreadPool::AddTask(void *pContext)
{
	static int idx = 0;
	while ((mpThread + idx%4)->isbusy==1);
	(mpThread + idx%4)->SetData(pContext);
	idx++;
	
}
void CLThreadPool::killall()//注意杀死所有线程要保证子线程都已完成任务
{

	for (int i = 0; i < mthnum; i++)
	{
		while ((mpThread + i)->isbusy == 1);//一直等到线程变为空闲才将其杀死
		(mpThread + i)->killself();
		(mpThread + i)->WaitForDeath();
		//mSourceLock->Lock();
		//cout << "thread " << i << ":" << "kill" << endl;
		//mSourceLock->Unlock();
	}

}
