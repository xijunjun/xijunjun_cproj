#include "CThread.h"
#include <string.h >
CLThread::CLThread()
{
	std::cout << "CLThread()" << std::endl;
	m_pContext = 0;
	int r = pthread_create(&m_ThreadID, 0, StartFunctionOfThread, this);
}

CLThread::~CLThread()
{
	std::cout << "~CLThread()" << std::endl;
}

void CLThread::set_config(int idnum, CLMutex*lock, sem_t *pmsem)
{
	thid = idnum;
	m_pmsem = pmsem;
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

CLMutex::CLMutex()
{
	int  r = pthread_mutex_init(&m_Mutex, 0);
	std::cout << "CLMutex()" << std::endl;
	if (r != 0)
	{
		throw "In CLMutex::CLMutex(), pthread_mutex_init error";
	}
}
CLMutex::~CLMutex()
{
	std::cout << "~CLMutex()" << std::endl;
	int r = pthread_mutex_destroy(&m_Mutex);
	if (r != 0)
	{
		std::cout << "wrong code:" <<r << std::endl;
		throw "In CLMutex::~CLMutex(), pthread_mutex_destroy error";
	}
}
void CLMutex::Lock()
{
	int r = pthread_mutex_lock(&m_Mutex);
}
void CLMutex::Unlock()
{
	int r = pthread_mutex_unlock(&m_Mutex);
}