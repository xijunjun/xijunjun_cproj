//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include<string>
//#include <fstream>
//#include<sstream>
//#include<time.h>
//using namespace std;
//#define CIN myin
//
//struct triple
//{
//	long long num;
//	long long div;
//	string s;
//	triple(long long x, long long y, string str) :num(x), div(y), s(str)
//	{}
//};
//bool cmp(triple a, triple b)
//{
//	return a.num < b.num;
//}
//int main()
//{
//	ifstream myin("input.txt");
//	int T;
//	CIN >> T;
//	for (int i = 0; i <= T - 1; i++)
//	{
//		int N, M;
//		CIN >> N;
//		vector<triple>p;
//		for (int j = 0; j <= N - 1; j++)
//		{
//			string str1, str2;
//			CIN >> str1 >> str2;
//			int k = str1.find_last_not_of('x');//这里还需要判断！！！
//			long long div = powl(10, 10 - k);
//			long long num = stoll(str1.substr(0, k + 1))*div;
//			p.push_back(triple(num, div, str2));
//		}
//		sort(p.begin(), p.end(), cmp);
//		CIN >> M;
//		for (int j = 0; j <= M - 1; j++)
//		{
//			string s;
//			CIN >> s;
//			int k = 0, lp = p.size();
//			long long snum = stoll(s);
//			triple temp(snum, 0, "");
//			auto it = lower_bound(p.begin(), p.end(), temp, cmp);
//			if ((it != p.end() && (*it).num == snum) || (it != p.begin() && ((*(--it)).num / (*it).div == stoll(s) / (*it).div)))
//				cout << (*it).s << endl;
//			else
//				cout << "unknown" << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}