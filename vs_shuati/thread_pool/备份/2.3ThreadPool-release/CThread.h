#ifndef CLTHREAD_H
#define CLTHREAD_H
#include <pthread.h>
#include<semaphore.h>
#include <iostream> 
class CLMutex
{
public:
	CLMutex();
	 ~CLMutex();
	void Lock();
	void Unlock();
private:
	CLMutex(const CLMutex&);
	CLMutex& operator=(const CLMutex&);
private:
	pthread_mutex_t m_Mutex;
};


class CLThread
{
private:
	pthread_t m_ThreadID;
public:
	CLThread();
	virtual ~CLThread();

	void SetData(void *pContext = 0);
	int WaitForDeath();
	void killself();
	static void* StartFunctionOfThread(void *pContext);
	virtual void RunThreadFunction() = 0;
	

	CLMutex mWaitLock;
	int thid = -1;
	bool mkillflag =0, isbusy = 0,initflag=0;
	void *m_pContext;
	
};

#endif
