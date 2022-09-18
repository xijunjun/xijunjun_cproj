#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
using namespace std;

int com_len(string s1, string s2)
{
	int l1 = s1.size(), l2 = s2.size(),i;
	if (l1 > l2)swap(l1,l2);
	for ( i = 0; i < l1; i++)
		if (s1[i] != s2[i])break;
	return i;
}
string  maxlen(string s)
{
	vector<string>suf_table;
	int len = s.size();
	for (int i = 0; i < len;i++)
		suf_table.push_back(s.substr(i,len-i));
	sort(suf_table.begin(), suf_table.end());
	string res;
	for (int i = 1; i < len; i++)
	{
		int coml = com_len(suf_table[i], suf_table[i-1]);
		if (coml>res.size())
			res = suf_table[i].substr(0, coml);
	}
	return res;
}

int main()
{
	#define CIN myin
	ifstream myin("input.txt");
	string s;
	CIN >> s;
	string res = maxlen(s);
	cout<<res<<" "<<res.size();

	system("pause");
	return 0;
}