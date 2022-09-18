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
	/*ע�⣬���ڴ������Taskָ�룬����Ҫ��Taskָ��ָ����ڴ���������ڳ��������߳���ȷ���ã�
	��������������tasklist��tasklist������������main��������������Ҫ��
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

//////////�̳߳����//////////////////////////////////////
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
