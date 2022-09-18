#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include <fstream>
#include<sstream>
#include<time.h>
#include<map>
using namespace std;
#define CIN myin

//优化后01背包
int maxval(int*aC, int *aW, int n, int C)
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
				f[j] = i == 0 ? aW[i] : max(f[j - aC[i]] + aW[i], f[j]);
				if (f[j] < 0)f[j] = -10000;
			}
		}
	}
	return f[C - 1];
}
int maxval(vector<pair<int, int>>&v,  int C)
{
	int n = v.size();
	vector<int>f((++C), -10000);
	f[0] = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = C - 1; j >= v[i].first; j--)
		{
			if (v[i].first <= 0)continue; 
			if (i == 0)
			{
				if (j == v[i].first)f[j] = v[i].second;
			}
			else 
			{
				f[j] =  max(f[j - v[i].first] + v[i].second, f[j]);
				if (f[j] < 0)f[j] = -10000;
			}
		}
	}
	return f[C - 1];
}

int maxval(vector<pair<int, int>>&v, int C,vector<int>&respath)
{
	int n = v.size();
	vector<int>f((++C), -10000);
	vector<vector<int>>path(C);
	f[0] = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = C - 1; j >= v[i].first; j--)
		{
			if (i == 0)
			{
				if (j == v[i].first){
					f[j] = v[i].second;
					path[j].push_back(i);
				}
			}
			else
			{
				if (f[j - v[i].first] + v[i].second > f[j])
				{
					f[j] = f[j - v[i].first] + v[i].second;
					path[j] = path[j - v[i].first];
					path[j].push_back(i);
				}
				if (f[j] < 0)f[j] = -10000;
			}
		}
	}
	respath = path[C-1];
	return f[C - 1];
}
int max_val_cnt(vector<pair<int, int>>&v, int C)
{
	vector<int>path;
	int top1 = maxval(v, C, path);
	if (top1 < 0)return -10000;
	for (int i = 0; i < path.size();i++)
	{
		v[path[i]].first = -v[path[i]].first;
	}
	int top2 = maxval(v, C);
	for (int i = 0; i < path.size(); i++)
	{
		v[path[i]].first = -v[path[i]].first;
	}
	if (top2 < 0)return -10000;
	return top1 + top2;
}


int main()
{
	//int arrayC[] = { 2, 3, 4, 5, 9 };//体积
	//int arrayW[] = { 30, 4, 5, 8, 10 };//价值
	//int arrayC[] = { 3, 2, 1, 1 };//体积
	//int arrayW[] = { 1,2,4,4 };//价值
	//cout << maxval(arrayC, arrayW, 4, 3) << endl;
	ifstream myin("input.txt");
	int n;
	CIN >> n;
	vector<pair<int, int>>v;
	int sum = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		pair<int, int>tp;
		CIN >> tp.first >> tp.second;
		sum += tp.first;
		v.push_back(tp);
	}
	//vector<int>path;
	//cout << max_val_cnt(v, 2) << endl;
	int maxscore = 0;


	sum = sum >> 1;
	for (int i = 1; i <=sum;i++)
	{
		int temp=max_val_cnt(v, i);
		if (temp > maxscore)
			maxscore = temp;
	}
	cout << maxscore << endl;

	cout << "end" << endl;
	system("pause");
}