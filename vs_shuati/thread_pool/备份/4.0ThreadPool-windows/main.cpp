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
	/*ע�⣬���ڴ������Taskָ�룬����Ҫ��Taskָ��ָ����ڴ���������ڳ��������߳���ȷ���ã�
	��������������tasklist��tasklist������������main��������������Ҫ��
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
