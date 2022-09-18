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

	long table[] = {10,20,30,40};
	thpool.AddTask(&table[0]);
	thpool.AddTask(&table[1]);
	thpool.AddTask(&table[2]);
	thpool.AddTask(&table[3]);
	//cout << "********" << endl;

	//Sleep(200);
	thpool.killall();

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