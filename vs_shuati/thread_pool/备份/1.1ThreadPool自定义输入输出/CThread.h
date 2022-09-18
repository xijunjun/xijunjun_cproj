#ifndef CLTHREAD_H
#define CLTHREAD_H
#include "CLMutex.h"
#include <pthread.h>


class CLThread
{
public:
	CLThread();
	virtual ~CLThread();

	void SetData(void *pContext = 0);
	int WaitForDeath();
	int thid = -1;
	void set_config(int idnum, CLMutex*lock);
	CLMutex mWaitLock, *mSourceLock=NULL;
	void killself();

	static void* StartFunctionOfThread(void *pContext);


	virtual void RunThreadFunction() = 0;
	bool mkillflag =0, isbusy = 0,initflag=0;
	void *m_pContext;
	pthread_t m_ThreadID;
	bool getflag();
};

#endif
