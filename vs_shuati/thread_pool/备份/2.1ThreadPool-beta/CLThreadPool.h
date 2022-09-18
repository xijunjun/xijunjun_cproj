#ifndef CLTHREADPOOL_H
#define CLTHREADPOOL_H
#include "CThread.h"
#include <vector>  
class CLApply : public CLThread
{
public:
	//在传入子线程指针时，需要考虑指针所指向对象的生存时间，假设传入局部变量的指针，局部变量销毁过后，子线程指向的内容将不确定
	virtual void RunThreadFunction();
};
struct Task
{
	char *input;
	std::vector <char> &output;
};
class CLThreadPool
{
public:
	CLThreadPool(int num);
	void waitInit();
	void AddTask(void *pContext);
	void killall();
	~CLThreadPool();
//protected:
	CLMutex mSourceLock ;
	void *m_pContext;
	CLThread *mpThread = NULL;
	sem_t m_pmsem;
	int mthnum = 0;
};
#endif