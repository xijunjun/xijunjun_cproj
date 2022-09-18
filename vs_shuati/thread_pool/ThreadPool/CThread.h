#ifndef CLTHREAD_H
#define CLTHREAD_H
#include <windows.h>
#include <iostream> 
class CLMutex
{
public:
	CLMutex();
	 ~CLMutex();
	void Lock();
	void Unlock();
	int Trylock();
private:
	CLMutex(const CLMutex&);
	CLMutex& operator=(const CLMutex&);
private:
	HANDLE m_Mutex;
};


class CLThread
{
private:
	HANDLE m_ThreadID;
public:
	CLThread();
	virtual ~CLThread();

	void SetData(void *pContext = 0);
	DWORD WaitForDeath();
	void killself();
	static DWORD WINAPI  StartFunctionOfThread(void *pContext);
	virtual void RunThreadFunction() = 0;
	

	CLMutex mWaitLock;
	int thid = -1;
	bool mkillflag =0, isbusy = 0,initflag=0;
	void *m_pContext;
	
};

#endif
