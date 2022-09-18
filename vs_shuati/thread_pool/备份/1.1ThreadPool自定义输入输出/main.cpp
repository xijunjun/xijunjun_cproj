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


	CLThreadPool thpool(4);
	//Sleep(1);

	string str = "abcdefghijklmnopqrst";
	vector <char> result;
	int tasknum = 20;



	///////////正确写法///////////////////////////
	vector<Task>tasklist;
	for (int i = 0; i < tasknum; i++)
	{
		Task onetask = { &str[i], result };
		tasklist.push_back(onetask);
	}
	for (int i = 0; i < tasknum; i++)
	{
		
		thpool.AddTask(&tasklist[i]);
		//thpool.AddTask(&str[i]);
	}
	/*------错误写法-----下面的写法onetask的生命周期无法保证子线程正确使用
	for (int i = 0; i < tasknum; i++)
	{
		Task onetask = { &str[i], result };
		thpool.AddTask(&onetask);
	}
	*/

	//thpool.AddTask(&str[0]);
	//thpool.AddTask(&str[1]);
	//thpool.AddTask(&str[2]);
	//thpool.AddTask(&str[3]);
	//cout << "********" << endl;

	//Sleep(200);
	thpool.killall();
	cout << "result:";
	for (int i = 0; i <result.size(); i++)
	{
		cout << result[i];
	}
	cout << endl;
	double cons = clock() - start;
	cons = cons;
	cout << "time:" << cons << endl;



	while (1);
	system("pause");
	return 0;
}




//#include <iostream>
//#include<time.h>
//#include<string>
//#include<Windows.h>
//using namespace std;
//int cac(int a);
//
//int main()
//{
//	string str = "abcdefghijklmnopqrst";
//	int tasknum = 20;
//
//	double start = clock();
//	for (int i = 0; i < tasknum; i++)
//	{
//		cout << str[i] << endl;
//		Sleep(100);
//	}
//	double cons = clock() - start;
//	cons = cons / CLOCKS_PER_SEC;
//	cout << "time:" << cons << endl;
//
//
//	system("pause");
//}