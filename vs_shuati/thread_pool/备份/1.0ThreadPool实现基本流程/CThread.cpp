#include "CThread.h"
#include <iostream> 

CLThread::CLThread()
{
	m_pContext = 0;
	//mWaitLock.Lock();
	int r = pthread_create(&m_ThreadID, 0, StartFunctionOfThread, this);
}

CLThread::~CLThread()
{
}

void CLThread::set_config(int idnum, CLMutex*lock)
{
	thid = idnum;
	mSourceLock = lock;
}
void CLThread::killself()
{
	mkillflag = 1;
	mWaitLock.Unlock();

}
void CLThread::SetData(void *pContext)
{
	isbusy = 1;
	m_pContext = pContext;
	mWaitLock.Unlock();	
}

int CLThread::WaitForDeath()
{

	int r = pthread_join(m_ThreadID, 0);
	return r;
}

void* CLThread::StartFunctionOfThread(void *pThis)
{
	CLThread *pThreadThis = (CLThread *)pThis;

	 pThreadThis->RunThreadFunction();
	 return 0;
}
