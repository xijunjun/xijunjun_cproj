#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//01����-��̬�滮
int maxval1(int*aC, int *aW, int n, int C)
{
	vector<int>f((++C)*n, 0);
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = 0; j <= C - 1; j++)
		{
			if (i == 0)
				f[i*C + j] = aC[i] <= j ? aW[i] : 0;
			else if (aC[i] <= j)
				f[i*C + j] = max(f[(i - 1)*C + j - aC[i]] + aW[i], f[(i - 1)*C + j]);
			else
				f[i*C + j] = f[(i - 1)*C + j];
		}
	}
	return f[C*n - 1];
}
//�����01���������������ֵ
int maxval2(int*aC, int *aW, int n, int C)
{
	vector<int>f((++C), 0);
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = C - 1; j >= aC[i]; j--)
		{
			f[j] = i == 0 ? aW[i] : max(f[j - aC[i]] + aW[i], f[j]);
		}
		cout << endl;
	}
	return f[C- 1];
}

//��·����01����
int maxval3(int*aC, int *aW, int n, int C)
{
	vector<int>f((++C), -10000);
	vector<vector<bool>>state(n,vector<bool>(C,0));
	f[0] = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = C - 1; j >= aC[i]; j--)
		{
			if (i == 0)
			{
				if (j = aC[i]){ f[j] = aW[i]; state[i][j] = 1; }
			}
			else
			{
				int chosen = f[j - aC[i]] + aW[i];
				if (chosen>0 && chosen > f[j])
				{
					f[j] =chosen;
					state[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < state.size(); i++)
	{
		for (int j = 0; j < state[i].size(); j++)
		cout << state[i][j] << ",";
		cout << endl;
	}
	cout << endl;

	//for (int i = n-1, j = C-1; i>0 && j>0; i--){ //·����¼
	//	if (state[i][j]) {//��i����Ʒ�Ƿ��������ʣ��j�İ���
	//		printf("i=%d ", i);
	//		j -= aC[i];//��ȥ��ǰ�Ѿ��������Ʒռֵ���ʣ�������
	//		cout << endl;
	//	}
	//}
	return f[C - 1];
}
//�󽫱���װ������µ����ֵ,���޷�װ���򷵻�-10000��
//���践�����޷�װ������µ����ֵ����ֱ��ȡ���������ֵ���ؼ��ɣ�������ֵ�ĺ������ڵ�ǰ�����ܸպ�װ�����ܻ�õ�����ֵ��
//ע���ʱ��һ������Խ���ֵԽ����Ϊ��һ���պ�װ�������ƣ�װ�������ȼ������ܼ�ֵ�����ȼ���
//��Ҫ����װ�������������������򷵻ش��������һ������0��������
int maxval4(int*aC, int *aW, int n, int C)
{
	vector<int>f((++C), -10000);
	f[0] = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = C - 1; j >= aC[i]; j--)
		{
			if (i == 0)
			{
				if (j == aC[i])f[j] = aW[i];
			}
			else
			{
				f[j] =  max(f[j - aC[i]] + aW[i], f[j]);
				if (f[j] < 0)f[j] = -10000;
			}
		}
		for (int i = 0; i < f.size(); i++)
		{
			cout << f[i] << ",";
		}
		cout << endl;
	}
	return f[C - 1];
}

int main()
{
	int arrayC[] = { 2, 7,3, 4, 9 };//���
	int arrayW[] = { 3,1, 4, 5, 10 };//��ֵ

	cout << maxval3(arrayC, arrayW, 5, 7) << endl;

	cout << "end" << endl;
	system("pause");
}