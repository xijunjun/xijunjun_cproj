#include "CLThreadPool.h"
#include <iostream>  
#include <Windows.h>  
using namespace std;

class CLApply : public CLThread
{
public:
	virtual void RunThreadFunction()
	{
		initflag = 1;
		mWaitLock.Lock();//���߳̿��ܻ�û�����߳�������������Ѿ�������unlock�Ļ�������
		while (1)
		{
		//ע��˴�������Ҫ��mSourceLock->Unlock();֮ǰд���룬���дҪ�������̶߳Թ����������繫����������Ƿ��ʼ����ɣ�
		 mWaitLock.Lock();//lock�ĺ���������ǰ�����ã��������������������ǰ�������ã���ȴ������ù��󣬲�����,Ȼ�������
		 if (mkillflag == 1 && isbusy==0){ break; }//ע��Ҫ��֤����������ɺ���ɱ��
		 Sleep(100);
		 long i = *((long*)m_pContext);
		 mSourceLock->Lock();
		 cout <<"thread "<<thid<<":"<< i << endl;
		 mSourceLock->Unlock();
		 isbusy = 0;
		}
		//mSourceLock->Lock();
		//cout << "thread " << thid << ":" << "exit()" << endl;
		//mSourceLock->Unlock();
	}

};
CLThreadPool::CLThreadPool(int num)//ע��ThreadPool�Ĺ��캯����Ҫһ���ĳ�ʼ��ʱ��
{
	mthnum = num;
	//cout << "num:" << num << endl;
	mpThread= new CLApply[num];
	for (int i = 0; i < num; i++)//ע��˴���
	{
		(mpThread + i)->set_config(i, mSourceLock);
	}
	waitInit();
}
void CLThreadPool::waitInit()//�ȴ������̳߳�ʼ����initflag = 1�ĵط�
{
	for (int i = 0; i < mthnum; i++)
	{
		while ((mpThread + i)->initflag == 0);
	}
}
void CLThreadPool::AddTask(void *pContext)
{
	static int idx = 0;
	//while ((mpThread + idx)->initflag==0);
	(mpThread + idx)->SetData(pContext);
	idx++;
	
}
void CLThreadPool::killall()//ע��ɱ�������߳�Ҫ��֤���̶߳����������
{

	for (int i = 0; i < mthnum; i++)
	{
		//mSourceLock->Lock();
		//cout << "thread " << i << ":" << "tokill  " << (mpThread + i)->isbusy << endl;
		//mSourceLock->Unlock();
		while ((mpThread + i)->isbusy == 1);//һֱ�ȵ��̱߳�Ϊ���вŽ���ɱ��
		(mpThread + i)->killself();
		(mpThread + i)->WaitForDeath();
		//mSourceLock->Lock();
		//cout << "thread " << i << ":" << "kill" << endl;
		//mSourceLock->Unlock();
	}

}
