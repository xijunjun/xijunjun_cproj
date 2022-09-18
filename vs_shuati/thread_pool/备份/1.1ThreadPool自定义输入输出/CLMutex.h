#ifndef CLMutex_H
#define CLMutex_H

#include <pthread.h>

class CLMutex
{
public:
	/*
	���캯����������������ʱ�����׳��ַ��������쳣
	*/
	CLMutex();
	virtual ~CLMutex();

	void Lock();
	void Unlock();

private:
	CLMutex(const CLMutex&);
	CLMutex& operator=(const CLMutex&);

private:
	pthread_mutex_t m_Mutex;
};

#endif