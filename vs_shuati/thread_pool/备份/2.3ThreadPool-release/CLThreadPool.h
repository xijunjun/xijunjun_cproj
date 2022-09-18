#ifndef CLTHREADPOOL_H
#define CLTHREADPOOL_H
#include "CThread.h"
#include <vector>  
class CLApply : public CLThread
{
public:
	//�ڴ������߳�ָ��ʱ����Ҫ����ָ����ָ����������ʱ�䣬���贫��ֲ�������ָ�룬�ֲ��������ٹ������߳�ָ������ݽ���ȷ��
	virtual void RunThreadFunction();
	CLMutex  *mSourceLock = NULL;
	sem_t *m_pmsem;
	void set_config(int idnum, CLMutex*lock, sem_t *pmsem);
	void CustomFunc();
};
struct Task
{
	char *input;
	std::vector <char> &output;
};
class CLThreadPool
{
public:
	CLThreadPool(int num);
	void waitInit();
	void AddTask(void *pContext);
	void killall();
	~CLThreadPool();
//protected:
	CLMutex mSourceLock ;
	void *m_pContext;
	CLApply *mpThread = NULL;
	sem_t m_pmsem;
	int mthnum = 0;
	
};
#endif