#include<iostream>
#include<vector>
using namespace std;
vector<int>getnext(string p)
{
	int lp = p.size();
	vector<int>next(lp,-1);
	for (int i = 1; i <= lp - 1; i++)
	{
		int k = next[i-1];
		while (1)
		{
			if (k == -1 || p[k] == p[i - 1])
			{
				next[i] = k + 1;
				break;
			}
			else
				k = next[k];
		}
	}
	return next;
}
vector<int> kmp(string s,string p)
{
	int cnt = 0;
	int ls = s.size(), lp = p.size(),j=0;
	vector<int>res;
	if (lp > ls)return res;
	vector<int>next = getnext(p);
	for (int i = 0; i <= ls - lp;)
	{
		cnt++;
		for (; j <= lp - 1; j++)
		{
			if (p[j] != s[i + j])
				break;
		}
		if (j == lp)
		{
			res.push_back(i);
			j--;
		}
		i = i + j - next[j];
		j = next[j]>0?next[j]:0;
	}
	cout << cnt << endl;
	return res;
}
int main()
{
	string s = "ababcabcacbab";
	vector<int>a = kmp(s, "abcac");
	//string s = "ababcabcabd";
	//vector<int>a = kmp(s,"abcabd");
	for (int i = 0; i <= a.size() - 1; i++)
	{
		cout << a[i] << endl;
	}
	system("pause");
}