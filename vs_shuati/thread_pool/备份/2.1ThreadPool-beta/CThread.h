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
public:
	CLThread();
	virtual ~CLThread();

	void SetData(void *pContext = 0);
	int WaitForDeath();
	int thid = -1;
	void set_config(int idnum, CLMutex*lock, sem_t *pmsem);
	CLMutex mWaitLock, *mSourceLock=NULL;
	void killself();

	static void* StartFunctionOfThread(void *pContext);


	virtual void RunThreadFunction() = 0;
	bool mkillflag =0, isbusy = 0,initflag=0;
	void *m_pContext;
	pthread_t m_ThreadID;
	bool getflag();
	sem_t *m_pmsem;
};

#endif
