#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	#define CIN myin
	ifstream myin("input.txt");
	string s;
	int n, m;
	CIN >> n >> m>>s;
	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int cnta = 0;
		int j;
		for ( j = i; j < s.size(); j++)
		{
			if (s[j] == 'a')
				cnta++;
			int cntb=j - i + 1 - cnta,dif;
			dif = min(cnta,cntb);
			if (dif>m)
				break;
		}
		if (res < j - i + 1)
			res = j - i + 1;
	}
	cout << res-1;
	system("pause");
	return 0;
}