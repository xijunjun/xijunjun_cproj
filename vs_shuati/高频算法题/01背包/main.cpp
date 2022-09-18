#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//01背包-动态规划
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
//极简版01背包，可求得最大价值
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

//带路径的01背包
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

	//for (int i = n-1, j = C-1; i>0 && j>0; i--){ //路径记录
	//	if (state[i][j]) {//第i件物品是否放入容量剩余j的包中
	//		printf("i=%d ", i);
	//		j -= aC[i];//减去当前已经放入的物品占值后的剩余包容量
	//		cout << endl;
	//	}
	//}
	return f[C - 1];
}
//求将背包装满情况下的最大值,若无法装满则返回-10000，
//若需返回在无法装满情况下的最大值，则直接取数组中最大值返回即可，数组中值的含义是在当前容量能刚好装满所能获得的最大价值，
//注意此时不一定容量越大价值越大，因为有一个刚好装满的限制，装满的优先级大于总价值的优先级。
//若要求尽量装满背包，即最大化体积，则返回从右向左第一个大于0的正数。
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
	int arrayC[] = { 2, 7,3, 4, 9 };//体积
	int arrayW[] = { 3,1, 4, 5, 10 };//价值

	cout << maxval3(arrayC, arrayW, 5, 7) << endl;

	cout << "end" << endl;
	system("pause");
}