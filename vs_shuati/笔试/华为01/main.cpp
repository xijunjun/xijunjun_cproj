#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;

vector<int>getnext(string p)
{
	int lp = p.size();
	vector<int>next(lp, -1);
	for (int i = 1; i <= lp - 1; i++)
	{
		int k = next[i - 1];
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
bool kmp(string s, string p)
{
	int ls = s.size(), lp = p.size(), j = 0;
	vector<int>res;
	if (lp > ls)return false;
	vector<int>next = getnext(p);
	for (int i = 0; i <= ls - lp;)
	{
		for (; j <= lp - 1; j++)
		{
			if (p[j] != s[i + j])
				break;
		}
		if (j == lp)
			return true;
		i = i + j - next[j];
		j = next[j]>0 ? next[j] : 0;
	}
	return false;
}
//singer_周杰 | 周杰伦 | 刘德华 | 王力宏; song_冰雨 | 北京欢迎你 | 七里香; actor_周杰伦 | 孙俪
//请播放周杰伦的七里香给我听

int main()
{
    #define CIN myin
	ifstream myin("input.txt");
	string s,s2;
	CIN >> s>>s2;
	//cout << s;
	s += ';';
	map<string, vector<string>>table;
	int ind = 0;
	vector<string>realval;
	string realname;

	while (1)
	{
		int i = s.find_first_of(";_|",ind);
		if (i == string::npos)
			break;
		if (s[i]=='_')
			realname=s.substr(ind, i - ind);
		else 
			table[realname].push_back(s.substr(ind, i - ind));
		ind = i + 1;
		//cout << *realname.rbegin() << endl;
	}
	//for (auto it : table)
	//{
	//	cout << it.first << endl;
	//	for (auto it2 : (it.second))
	//	{
	//		cout << it2 << endl;
	//	}
	//}
	int maxlen =0;
	string people;
	for (auto it : table["singer"])
	{
		if (it.size() > maxlen&&kmp(s2, it))
		{
			people = it;
			maxlen = it.size();
		}
	}
	cout << people<<endl;
	
	maxlen = 0;
	string song;
	for (auto it : table["song"])
	{
		if (it.size() > maxlen&&kmp(s2, it))
		{
			song = it;
			maxlen = it.size();
		}
	}
	cout << song << endl;

	string shuxing;
	for (auto it : table)
	{
		if (find(it.second.begin(), it.second.end(), people) != it.second.end())
		{
			shuxing += it.first + "\\";
		}
	}
	cout << shuxing << endl;

	system("pause");
	return 0;
}