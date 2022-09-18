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
{//////////////////注意线程池的内存释放！！！！！！

	//{ 
	//	CLApply  app1;
	//	Sleep(80);
	//	app1.killself();
	//	app1.WaitForDeath();
	//	Sleep(2000);
	//}
	CLMutex* pmux = new CLMutex[2];
	delete []pmux;

	{ 
		double start = clock();
		CLThreadPool thpool(10);

		string str = "abcdefghijklmnopqrst";
		vector <char> result;
		int tasknum = 20;

		/*注意，由于传入的是Task指针，所以要求Task指针指向的内存的生命周期持续到子线程正确引用，
		所以这里先生成tasklist，tasklist的生命周期是main函数结束，满足要求。
		*/
		vector<Task>tasklist;
		for (int i = 0; i < tasknum; i++)
		{
			Task onetask = { &str[i], result };
			tasklist.push_back(onetask);
		}
		for (int i = 0; i < tasknum; i++)
		{
			thpool.AddTask(&tasklist[i]);
		}

		thpool.killall();
		cout << "result:";
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
		}
		cout << endl;
		double cons = clock() - start;
		cons = cons;
		cout << "time:" << cons << endl;
	}
	//while (1);
	system("pause");
	return 0;
}
