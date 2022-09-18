#include "CLThreadPool.h"
#include <iostream>  
#include <Windows.h>  
using namespace std;

//�ڴ������߳�ָ��ʱ����Ҫ����ָ����ָ����������ʱ�䣬���贫��ֲ�������ָ�룬�ֲ��������ٹ������߳�ָ������ݽ���ȷ��
void CLApply::RunThreadFunction()
{
	initflag = 1;
	mWaitLock.Lock();//��Ҫ�������߳̿��ܻ�û�����߳�������������Ѿ�������unlock�Ļ�������
	while (1)
	{
	//ע��˴�������Ҫ��mSourceLock->Unlock();֮ǰд���룬���дҪ�������̶߳Թ����������繫����������Ƿ��ʼ����ɣ�
		mWaitLock.Lock();//lock�ĺ���������ǰ�����ã��������������������ǰ�������ã���ȴ������ù��󣬲�����,Ȼ�������
		if (mkillflag == 1 ){ break; }//ע��Ҫ��֤����������ɺ���ɱ��
		Sleep(10);
		Task onetask = *((Task*)m_pContext);
		mSourceLock->Lock();
		cout << "thread" << thid << ":" << *(onetask.input)<< " ";
		(onetask.output).push_back(int(*(onetask.input))-32);
		mSourceLock->Unlock();

		isbusy = 0;
		sem_post(m_pmsem);//�ź�����1
	}
	mWaitLock.Unlock();//ע�⣡��mutex�������ͷ�֮ǰһ��Ҫ����unlock������״̬��������pthread_mutex_destroy���������ش���ֵ
}

CLThreadPool::CLThreadPool(int num)//ע��ThreadPool�Ĺ��캯����Ҫһ���ĳ�ʼ��ʱ��
{
	
	mthnum = num;
	mpThread= new CLApply[num];
	for (int i = 0; i < num; i++)//ע��˴���
	{
		(mpThread + i)->set_config(i, &mSourceLock,&m_pmsem);
	}
	waitInit();
	sem_init(&m_pmsem, 0, num);//�ȴ��̳߳�ʼ����ɣ���������ʼ���ź���

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
void CLThreadPool::waitInit()//�ȴ������̳߳�ʼ����initflag = 1�ĵط�,����������̻߳�û��ʼ���������λ�ã����߳̾Ϳ�ʼaddtask���ο���linux�������ʵ����3.5.9
{
	for (int i = 0; i < mthnum; i++)
	{
		while ((mpThread + i)->initflag == 0);
	}
}
void CLThreadPool::AddTask(void *pContext)
{
	//���һ���źţ���Ҫ�ַ�һ��task
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
void CLThreadPool::killall()//ע��ɱ�������߳�Ҫ��֤���̶߳����������
{

	for (int i = 0; i < mthnum; i++)
	{
		while ((mpThread + i)->isbusy == 1);//һֱ�ȵ��̱߳�Ϊ���вŽ���ɱ��
		(mpThread + i)->killself();
		(mpThread + i)->WaitForDeath();
	}
}
