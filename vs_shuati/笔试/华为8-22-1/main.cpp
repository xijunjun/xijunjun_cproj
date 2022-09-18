#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
using namespace std;
int  maxlen(string s,int st)
{
	int flag=0,res=0;
	for (int i = st; i < s.size();i++)
	{
		if (s[i] == '(')
			flag++;
		else if (s[i] == ')')
			flag--;
		else
			flag = -1;
		if (flag == 0)
		{
			if (i - st + 1>res)
				res = i - st + 1;
		}
		if (flag < 0)break;
	}
	return res;
}
int max_val(string s)
{
	int res = 0;
	for (int i = 0; i < s.size();i++)
	{
		int ml = maxlen(s, i);
		if (ml>res)
			res = ml;
	}
	return res;
}
int main()
{
	#define CIN myin
	ifstream myin("input.txt");
	string s;
	CIN >> s;
	cout << max_val(s);
	system("pause");
	return 0;
}