#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
using namespace std;

bool isval(string s1, string s2)
{
	int len1 = s1.size(), len2 = s2.size();
	vector<vector<int>>d(len1 + 1, vector<int>(len2 + 1));
	int i, j;
	for (i = 0; i <= len1; i++)
		d[i][0] = i;
	for (j = 0; j <= len2; j++)
		d[0][j] = j;
	for (i = 1; i <= len1; i++)
	{
		for (j = 1; j <= len2; j++)
		{
			int cost = s1[i] == s2[j] ? 0 : 1;
			int deletion = d[i - 1][j] + 1;
			int insertion = d[i][j - 1] + 1;
			int substitution = d[i - 1][j - 1] + cost;
			d[i][j] = min(min(deletion, insertion), substitution);
		}
	}
	if (d[len1][len2] <= 1)return true;
	return false;
}


bool cmps(string s1, string s2, int ind)
{
	int len1 = s1.size(), len2 = s2.size();
	for (int i = 0; i < ind; i++)
	{
		if (s1[i] != s2[i])return false;
	}
	for (int i = ind + 1; i < len1; i++)
	{
		if (s1[i] != s2[i - 1])return false;
	}
	return true;
}
bool isval2(string s1, string s2)
{
	int len1 = s1.size(), len2 = s2.size();
	if (len1 <len2)swap(s1, s2);
	len1 = s1.size(), len2 = s2.size();
	if (len1 - len2>1)return false;
	if (len1 == len2)
	{
		int k = 1;
		for (int i = 0; i < len1; i++)
		{
			if (s1[i] != s2[i] && k == 0)
				return false;
			if (s1[i] != s2[i])
				k--;
		}
	}
	if (len1 - len2 == 1)
	{
		for (int i = 0; i < len1; i++)
		{
			if (cmps(s1, s2, i))return true;
		}
		return  false;
	}
	return true;
}

int main()
{
#define CIN myin
	ifstream myin("input.txt");
	string s1, s2;
	CIN >> s1 >> s2;
	cout << isval(s1, s2);
	system("pause");
	return 0;
}