#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
using namespace std;
int MAXVAL = 15;
int f(vector<int>&a,int n,int pre)
{
	if (n == a.size()-1)
	{
		if (pre <= a[n])
			return 1;
		return 0;
	}
	if (pre <= a[n])
	{
		return max(f(a,n +1, pre), 1 + f(a,n+1,a[n]));
	}
	else return f(a,n+1,pre);
}
int f2(vector<int>&a)
{
	
	vector<vector<int>>table(a.size(), vector<int>(MAXVAL, 0));
	int lastth = -100;
	for (int i = 0; i<a.size(); i++)
	{
		for (int th = 0; th < MAXVAL; th++)
		{
			if (i ==0)
			{
				if (a[i] >= th)
					table[i][th] = 1;
			}
			else {
				if (a[i] >= th)
					table[i][th] = table[i - 1][th]+1;
				else table[i][th] = table[i - 1][th];
			}
		}
	}

	int pre=0,res=0;
	for (int i = 0; i < a.size(); i++)
	{
		if (table[a.size() - 1][a[i]]>res)
			res = table[a.size() - 1][a[i]];
		//if (i == a.size() - 1)
		//{
		//	if (pre <= a[i])
		//	{
		//		pre = table[i][a[i]];
		//		pre = a[i];
		//	}
		//}
		//else if (pre <= a[i])
		//{
		//	if (table[i][a[i]]>table[i][pre])
		//		pre = a[i];
		//	res =table[i][pre];
		//}
	}



	//for (int i = 0; i < a.size(); i++)
	//{
	//	for (int th = 0; th < MAXVAL; th++)
	//	{
	//		cout << table[i][th] << ",";
	//	}
	//	cout << endl;
	//}
	return res;
}



int f3(vector<int>&a, int n, int pre)
{
	static vector<vector<int>>table(a.size(), vector<int>(MAXVAL, -1));
	if (n == a.size() - 1)
	{
		if (pre <= a[n])
			return 1;
		return 0;
	}
	if (pre <= a[n])
	{
		int s0, s1 ;
		if (table[n + 1][pre] != -1)
			s0 = table[n + 1][pre];
		else
		{
			s0 = f3(a, n + 1, pre);
			table[n + 1][pre]=s0;
		}
		if (table[n + 1][a[n]] != -1)
			s1 = table[n + 1][a[n]];
		else
		{
			s1 = f3(a, n + 1, a[n]);
			table[n + 1][a[n]] = s1;
		}
		return max(s0,1+s1);
	}
	else
	{
		int  s0;
		if (table[n + 1][pre] != -1)
			s0 = table[n + 1][pre];
		else
		{
			s0 = f3(a, n + 1, pre);
			table[n + 1][pre] = s0;
		}
		return s0;
	}
}

int main()
{
	#define CIN myin
	ifstream myin("input.txt");
	int n, t;
	CIN >> n >> t;
	vector<int>a(n);
	for (int i = 0; i < n;i++)
		CIN >> a[i];
	vector<int>b;
	for (int i = 0; i < n*t; i++)
		b.push_back(a[i%n]);
	cout<<f(b,0,0);
	while (1);
	for (int i = 1; i < n; i++)
	{
		if (a[i] != a[0])
		{
		cout << f(a, 0, 0) + t - 1;
			//cout << f2(a) + t - 1;
			system("pause");
			return 0;
		}
	}
	cout << n*t;
	system("pause");
	return 0;
}