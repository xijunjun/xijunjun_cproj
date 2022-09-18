#include "CLMutex.h"

CLMutex::CLMutex()
{
	int  r = pthread_mutex_init(&m_Mutex, 0);
	if (r != 0)
	{
		throw "In CLMutex::CLMutex(), pthread_mutex_init error";
	}
}

CLMutex::~CLMutex()
{
	int r = pthread_mutex_destroy(&m_Mutex);
	if (r != 0)
	{
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