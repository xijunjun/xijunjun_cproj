#include "CLThreadPool.h"
#include <iostream>  
#include <Windows.h>  
using namespace std;

void CLApply::set_config(int idnum, CLMutex*lock, HANDLE *pmsem)
{
	thid = idnum;
	m_pmsem = pmsem;
	mSourceLock = lock;
}

//�ڴ������߳�ָ��ʱ����Ҫ����ָ����ָ����������ʱ�䣬���贫��ֲ�������ָ�룬�ֲ��������ٹ������߳�ָ������ݽ���ȷ��
void CLApply::RunThreadFunction()
{	
	mWaitLock.Lock();//��Ҫ�������߳̿��ܻ�û�����߳�������������Ѿ�������unlock�Ļ�������
	initflag = 1;
	while (1)
	{
	  //ע��˴�������Ҫ��mSourceLock->Unlock();֮ǰд���룬���дҪ�������̶߳Թ����������繫����������Ƿ��ʼ����ɣ�
		mWaitLock.Lock();//lock�ĺ���������ǰ�����ã��������������������ǰ�������ã���ȴ������ù��󣬲�����,Ȼ�������
		if (mkillflag == 1 ){ break; }//ע��Ҫ��֤����������ɺ���ɱ��	
		CustomFunc();
		isbusy = 0;
		delete (Task*)m_pContext;//!!!!!!ע��˴�Ҫ��void*���͵�ָ��ǿתΪTask*���͵�ָ�룬����delete��Ч
		//sem_post(m_pmsem);//�ź�����1
		ReleaseSemaphore(*m_pmsem, 1, NULL);
	}
	mWaitLock.Unlock();//ע�⣡��mutex�������ͷ�֮ǰһ��Ҫ����unlock������״̬��������pthread_mutex_destroy���������ش���ֵ
}


void CLApply::CustomFunc()
{
	Sleep(100);
	Task onetask = *((Task*)m_pContext);
	mSourceLock->Lock();
	cout << "thread" << thid << ":" << *(onetask.input) << " "<<endl;
	(onetask.output).push_back(int(*(onetask.input)) - 32);
	mSourceLock->Unlock();
}



CLThreadPool::CLThreadPool(int num)//ע��ThreadPool�Ĺ��캯����Ҫһ���ĳ�ʼ��ʱ��
{
	
	mthnum = num;
	mpThread= new CLApply[num];
	for (int i = 0; i < num; i++)//ע��˴���
	{
		(mpThread + i)->set_config(i, &mSourceLock,&m_sem);
	}
	waitInit();
	//sem_init(&m_pmsem, 0, num);//�ȴ��̳߳�ʼ����ɣ���������ʼ���ź���
	m_sem = CreateSemaphore(NULL, num, num, NULL);
}
CLThreadPool::~CLThreadPool()
{
     std::cout << "~CLThreadPool()" << std::endl;
	delete []mpThread ;
	CloseHandle(m_sem);

}
void CLThreadPool::waitInit()//�ȴ������̳߳�ʼ����initflag = 1�ĵط�,����������̻߳�û��ʼ���������λ�ã����߳̾Ϳ�ʼaddtask���ο���linux�������ʵ����3.5.9
{
	for (int i = 0; i < mthnum; i++)
	{
		while ((mpThread + i)->mWaitLock.Trylock() == 0)
		{
			(mpThread + i)->mWaitLock.Unlock();
		}
		//while ((mpThread + i)->initflag == 0);
	}
}
void CLThreadPool::AddTask(void *pContext)
{
	//���һ���źţ���Ҫ�ַ�һ��task
//	sem_wait(&m_pmsem);
	WaitForSingleObject(m_sem, INFINITE);
	for (int i = 0; i < mthnum; i++)
	{
		if ((mpThread + i)->isbusy == 0 )
		{
			(mpThread + i)->SetData(pContext);
			break;
		}
	}
	
}
void CLThreadPool::killall()//ע��ɱ�������߳�Ҫ��֤���̶߳����������
{

	for (int i = 0; i < mthnum; i++)
	{
		while ((mpThread + i)->isbusy == 1);//һֱ�ȵ��̱߳�Ϊ���вŽ���ɱ��
		(mpThread + i)->killself();
		(mpThread + i)->WaitForDeath();
	}
}
