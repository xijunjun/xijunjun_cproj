#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include <fstream>
#include<sstream>
#include<time.h>
using namespace std;
#define CIN myin

bool cmp(pair<string, string> a, pair<string, string> b)//a,b是升序
{
	return a.first< b.first;
}
bool is_equal(pair<string, string> a, pair<string, string> b)
{
	for (int i = 0; i < a.first.size(); i++)
	{
		if (a.first[i] == 'x')
			return true;
		if (a.first[i] != b.first[i])
			return false;
	}
	return true;
}
//排序+二分查找
//注意字符串的
int main()
{
	ifstream myin("input.txt");
	int T;
	CIN >> T;
	for (int i = 0; i <= T - 1; i++)
	{
		int N, M;
		CIN >> N;
		vector<pair<string, string>>p;
		for (int j = 0; j <= N - 1; j++)
		{
			string str1, str2;
			CIN >> str1 >> str2;
			p.push_back(make_pair(str1, str2));
		}
		sort(p.begin(), p.end(), cmp);
		CIN >> M;
		for (int j = 0; j <= M - 1; j++)
		{
			string s;
			CIN >> s;
			int k = 0, lp = p.size();
			pair<string, string>pair_s = make_pair(s, s);
			auto it = lower_bound(p.begin(), p.end(), pair_s, cmp);
			if ((it != p.end() && is_equal(*(it), pair_s)))
				cout << (*it).second << endl;
			else
				cout << "unknown" << endl;
		}
	}
	system("pause");
	return 0;
}