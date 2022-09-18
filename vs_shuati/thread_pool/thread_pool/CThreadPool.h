#ifndef __CTHREAD  
#define __CTHREAD  
#include <vector>  
#include <string>  
#include <pthread.h>  

using namespace std;

/**
ִ��������࣬�����������ݲ�ִ��
**/
class CTask
{
protected:
	string m_strTaskName;  //���������  
	void* m_ptrData;       //Ҫִ�е�����ľ�������  
public:
	CTask(){}
	CTask(string taskName)
	{
		this->m_strTaskName = taskName;
		m_ptrData = NULL;
	}
	virtual int Run() = 0;
	void SetData(void* data);    //������������  
};

/**
�̳߳�
**/

class CThreadPool
{
private:
	vector<CTask*> m_vecTaskList;         //�����б�  
	int m_iThreadNum;                            //�̳߳����������߳���             
	static vector<pthread_t> m_vecIdleThread;   //��ǰ���е��̼߳���  
	static vector<pthread_t> m_vecBusyThread;   //��ǰ����ִ�е��̼߳���  
	static pthread_mutex_t m_pthreadMutex;    //�߳�ͬ����  
	static pthread_cond_t m_pthreadCond;    //�߳�ͬ������������  
protected:
	static void* ThreadFunc(void * threadData); //���̵߳��̺߳���  
	static int MoveToIdle(pthread_t tid);//�߳�ִ�н����󣬰��Լ����뵽�����߳���  
	static int MoveToBusy(pthread_t tid);   //���뵽æµ�߳���ȥ  
	int Create();          //�������е��߳�  
public:
	CThreadPool(int threadNum);
	int AddTask(CTask *task);      //��������ӵ��̳߳���  
	int StopAll();
};
#endif