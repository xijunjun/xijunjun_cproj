#include "CThreadPool.h"  
#include <iostream>  
#include<Windows.h>
using namespace std;

class CWorkTask : public CTask
{
public:
	CWorkTask()
	{}
	int Run()
	{
		cout << (char*)this->m_ptrData << endl;
		Sleep(10);
		return 0;
	}
};

int main()
{
	CWorkTask taskObj;
	char szTmp[] = "this is the first thread running,haha success";
	taskObj.SetData((void*)szTmp);
	CThreadPool threadPool(10);
	for (int i = 0; i < 11; i++)
	{
		threadPool.AddTask(&taskObj);
	}
	while (1)
	{
		Sleep(120);
	}
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