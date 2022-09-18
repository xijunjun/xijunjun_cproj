#include "CLThreadPool.h"  
#include <iostream>  
#include<time.h>
using namespace std;

void cut(const int &a)
{
	cout << a << endl;
}

int main()
{

	double start = clock();
	

	string str = "abcdefghijklmnopqrst";
	vector <char> result;
	/*注意，由于传入的是Task指针，所以要求Task指针指向的内存的生命周期持续到子线程正确引用，
	所以这里先生成tasklist，tasklist的生命周期是main函数结束，满足要求。
	*/
	int thnum = 4;
	CLThreadPool thpool(thnum);
	//Sleep(500);
		for (int i = 0; i < str.size(); i++)
		{
			Task *onetask = new Task{ &str[i], result };
			thpool.AddTask(onetask);
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
