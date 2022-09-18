#include "CLThreadPool.h"  
#include <iostream>  
#include<Windows.h>
#include<time.h>
using namespace std;

class CLMyThread : public CLThread
{
public:
	virtual void RunThreadFunction()
	{
		long i = (long)m_pContext;
		cout << i << endl;
	}
};



int main()
{
	double start = clock();
	

	string str = "abcdefghijklmnopqrst";
	vector <char> result;
	/*注意，由于传入的是Task指针，所以要求Task指针指向的内存的生命周期持续到子线程正确引用，
	所以这里先生成tasklist，tasklist的生命周期是main函数结束，满足要求。
	*/
	vector<Task>tasklist;
	for (int j = 0; j < 100; j++)
	{
		for (int i = 0; i < str.size(); i++)
		{
			Task onetask = { &str[i], result };
			tasklist.push_back(onetask);
		}
	}

//////////线程池相关//////////////////////////////////////
	CLThreadPool thpool(10);
	for (int i = 0; i < tasklist.size(); i++)
	{
		thpool.AddTask(&tasklist[i]);
	}
	thpool.killall();
//////////////////////////////////////////////

	cout << "result:";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}
	cout << endl << "result.size():" << result.size()<<endl;
	double cons = clock() - start;
	cons = cons;
	cout << "time:" << cons << endl;

	system("pause");
	return 0;
}
