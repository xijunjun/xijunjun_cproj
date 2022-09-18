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
{//////////////////ע���̳߳ص��ڴ��ͷţ�����������

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

		/*ע�⣬���ڴ������Taskָ�룬����Ҫ��Taskָ��ָ����ڴ���������ڳ��������߳���ȷ���ã�
		��������������tasklist��tasklist������������main��������������Ҫ��
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
