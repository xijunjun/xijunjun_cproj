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
bool is_equal(string a, string b)
{
	int k = a.find_last_not_of('x');
	return a.substr(0, k + 1) == b.substr(0, k + 1);
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
		map<string, string>mp;
		for (int j = 0; j <= N - 1; j++)
		{
			string str1, str2;
			CIN >> str1 >> str2;
			mp[str1] = str2;
		}
		CIN >> M;
		for (int j = 0; j <= M - 1; j++)
		{
			string s;
			CIN >> s;
			auto it = mp.lower_bound(s);
			if (it != mp.end() && is_equal((*it).first, s))
				cout << (*it).second << endl;
			else
				cout << "unknown" << endl;
		}
	}
	system("pause");
	return 0;
}