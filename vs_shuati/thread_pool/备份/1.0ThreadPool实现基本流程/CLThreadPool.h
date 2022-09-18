#ifndef CLTHREADPOOL_H
#define CLTHREADPOOL_H
#include<semaphore.h>
#include "CThread.h"
#include <vector>  
class CLThreadPool
{
public:
	CLThreadPool(int num);
	void waitInit();
	void AddTask(void *pContext);
	void killall();
	~CLThreadPool()
	{
	}
protected:
	//vector<void*>tasklist;
	CLMutex *mSourceLock = new CLMutex();
	void *m_pContext;
	CLThread *mpThread = NULL;
	sem_t sem;
	int mthnum = 0;
	
};
#endif