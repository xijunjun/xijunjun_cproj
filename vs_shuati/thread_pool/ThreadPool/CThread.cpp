#include "CThread.h"
#include <string.h >
CLThread::CLThread()
{
	//std::cout << "CLThread()" << std::endl;
	m_pContext = 0;
	CreateThread(NULL, 0, StartFunctionOfThread, this, 0, NULL);
}

CLThread::~CLThread()
{
	//std::cout << "~CLThread()" << std::endl;
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

DWORD CLThread::WaitForDeath()
{
	DWORD r =WaitForSingleObject(m_ThreadID, INFINITE);
	return r;
}

DWORD WINAPI CLThread::StartFunctionOfThread(void *pThis)
{
	CLThread *pThreadThis = (CLThread *)pThis;
	 pThreadThis->RunThreadFunction();
	 return 0;
}

CLMutex::CLMutex()
{
	m_Mutex = CreateEvent(NULL, FALSE, TRUE, NULL);
	//std::cout << "CLMutex()" << std::endl;

}
CLMutex::~CLMutex()
{
	//std::cout << "~CLMutex()" << std::endl;
	CloseHandle(m_Mutex);
	m_Mutex = NULL;
}
void CLMutex::Lock()
{
	WaitForSingleObject(m_Mutex, INFINITE);
}
void CLMutex::Unlock()
{
	SetEvent(m_Mutex);
}
int CLMutex::Trylock()
{
	DWORD dwWaitResult;

	dwWaitResult = WaitForSingleObject(m_Mutex, 0);
	return (dwWaitResult == WAIT_OBJECT_0) ? 0 : -1;
}