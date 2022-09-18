#include <iostream>
#include<vector>
using namespace std;


bool isnum(char* str, int st, int ed)
{
	string arr = "s+-1..1";
	bool table[7][8] =
	{//// 0  1  2  3  4  5  6  7
		{ 0, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 1, 1 }
	};
	int stat=0;
	while (1)
	{
		bool isend=true;
		for (int i = 0; i < 8;i++)
		{
			char val;
			if (st == ed + 1)val = 0;
			else val = (*(str + st) >= '0'&&*(str + st) <= '9') ? '1' : *(str + st);
			if (table[stat][i] == 1 && val == arr[i])
			{
				isend = false;
				stat = i;
				if (stat == 7)return true;
				break;
			}
		}
		if (isend)return false;//如果上次状态没有得到更新，那么匹配失败
		st++;
	}
}
bool isnum2(char* str)
{
	string arr = "s+-1..1";
	bool table[7][8] =
	{//// 0  1  2  3  4  5  6  7
		{ 0, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 1, 1 }
	};
	int stat = 0;
	while (1)
	{
		bool isend = true;
		for (int i = 0; i < 8; i++)
		{
			char val = (*str >= '0'&&*str <= '9') ? '1' : *str;
			if (table[stat][i] == 1 && val == arr[i])
			{
				isend = false;
				stat = i;
				if (stat == 7)return true;
				break;
			}
		}
		if (isend)return false;//如果上次状态没有得到更新，那么匹配失败
		str++;
	}
}
//需要注意：".5","5."都是合法的数，
class Solution {
public:
	//判断无e字符串是否是数的子函数
	//几种状态：s态，+态，-态，小数点前输入n的n1态，没输过n后输入了.的d1态，输入过n后输入了.的d2态，小数点后输入n的n2态，终态
	bool isnum(char* str, int st, int ed)
	{
		string arr = "s+-1..1";//要转换到对应索引需要输入的字符，比如要转换到状态2那么输入必须为-
		//状态可转移数组，第0行记录了从状态0可以转换到第几个状态，状态0可以转换到状态1、2、3、4,。状态1可转换到状态3和4。
		//接下来的工作就是根据输入值遍历可转换状态并且转换到相应的状态，若某一次转换失败则返回false。
		bool table[7][8] =
		{//// 0  1  2  3  4  5  6  7
			{ 0, 1, 1, 1, 1, 0, 0, 0 },
			{ 0, 0, 0, 1, 1, 0, 0, 0 },
			{ 0, 0, 0, 1, 1, 0, 0, 0 },
			{ 0, 0, 0, 1, 0, 1, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 1, 1 },
			{ 0, 0, 0, 0, 0, 0, 1, 1 }
		};
		int stat = 0;
		while (1)
		{
			bool isend = true;
			for (int i = 0; i < 8; i++)
			{
				char val;
				if (st == ed + 1)val = 0;
				else val = (*(str + st) >= '0'&&*(str + st) <= '9') ? '1' : *(str + st);
				if (table[stat][i] == 1 && val == arr[i])
				{
					isend = false;
					stat = i;
					if (stat == 7)return true;
					break;
				}
			}
			if (isend)return false;//如果上次状态没有得到更新，那么匹配失败
			st++;
		}
	}
    //为了容易理解，将问题分为有e和无e两种情况来分析，若含有一个e，那么e前面的字符串必须为不含e的数，e后面的数必须为不含e的整数。
	//于是就需要写一个判断无e字符串是否是数的子函数。
	bool isNumeric(char* string)
	{
		if (*string == 0)
			return false;
		int inde = 0, inddot = 0, ind = 0;
		int cnt = 0;
		while (string[ind++] != 0)
		{
			if (string[ind] == 'e' || string[ind] == 'E')
			{
				if (cnt == 0)
				{
					inde = ind;
					cnt++;
				}
				else 
					return false;
			}
			else if (string[ind] == '.')
			{
				inddot = ind;
				if (cnt == 1 && inddot>inde)
					return false;
			}
		}
		if (inde != 0)
			return isnum(string, 0, inde - 1) && isnum(string, inde + 1, --(--ind));
		else 
			return isnum(string, 0, --(--ind));
	}
};

//网络版本有点问题，.5这种通不过
class Solution2 {
public:

	bool isNumeric(char* string) {
		char *arr = "+-n.ne+-n";
		int turn[10][9] = {
			//+  -  n  .  n  e  +  -  n
			{ 1, 1, 1, 0, 0, 0, 0, 0, 0 },// # start
			{ 0, 0, 1, 1, 0, 0, 0, 0, 0 },// +
			{ 0, 0, 1, 1, 0, 0, 0, 0, 0 },// -
			{ 0, 0, 1, 1, 0, 1, 0, 0, 0 },// n
			{ 0, 0, 0, 0, 1, 0, 0, 0, 0 },// .
			{ 0, 0, 0, 0, 1, 1, 0, 0, 0 },// n
			{ 0, 0, 0, 0, 0, 0, 1, 1, 1 },// e
			{ 0, 0, 0, 0, 0, 0, 0, 0, 1 },// +
			{ 0, 0, 0, 0, 0, 0, 0, 0, 1 },// -
			{ 0, 0, 0, 0, 0, 0, 0, 0, 1 } // n
		};
		int cur = 0;
		for (int j, i = 0; string[i]; i++) {
			for (j = 0; j < 9; j++) {
				if (turn[cur][j]) {
					if (('0' <= string[i] && string[i] <= '9' && arr[j] == 'n') ||
						(string[i] == 'E' && arr[j] == 'e') ||
						string[i] == arr[j]) {
						cur = j + 1;
						break;
					}
				}
			}
			if (j == 9) return false;
		}
		if (cur == 3 || cur == 4 || cur == 5 || cur == 9)
			return true;
		return false;
	}
};
//2018-8-23
class Solution3 {
public:
	bool isnum(char *s)
	{
		if (!s)return false;
		int len = strlen(s), signflag = 0, dotflag = 0, numflag = 0;
		if (s[0] == '+' || s[0] == '-')signflag = 1;
		for (int i =signflag ; i < len; i++)
		{
			if (dotflag == 0 && s[i] == '.')
				dotflag = 1;
			else if (s[i]<'0' || s[i]>'9')
				return false;
			numflag = 1;
		}
		return numflag;
	}
	bool isNumeric(char* s) {
		if (!s)return false;
		int len = strlen(s);
		int ind = strcspn(s,"eE");
		if (ind == len)
			return isnum(s);
		if (strchr(s + ind + 1, '.'))
			return false;
		s[ind] = 0;
		return isnum(s) && isnum(s+ind+1);
	}
};
//string版本
class Solution4{
public:
	bool isnum(string s)
	{
		if (s.empty())return false;
		int len = s.size(), signflag = 0, dotflag = 0, numflag = 0;
		if (s[0] == '+' || s[0] == '-')signflag = 1;
		for (int i = signflag; i < len; i++)
		{
			if (dotflag == 0 && s[i] == '.')
				dotflag = 1;
			else if (s[i]<'0' || s[i]>'9')
				return false;
			numflag = 1;
		}
		return numflag;
	}
	bool isNumeric(string s) {
		if (s.empty())return false;
		int len = s.size();
		int ind = s.find_first_of("eE");
		if (ind == string::npos)
			return isnum(s);
		if (s.find_first_of( ind+1,'.')!=string::npos)
			return false;
		return isnum(s.substr(0,ind)) && isnum(s.substr(ind+1));
	}
};
int main()
{
	Solution4 mys;
	string arr = "s+-1..1";

	cout << isnum("+6", 0, 5) << endl;

	cout << mys.isNumeric(".5") << endl;

	cout << "end" << endl;
	system("pause");
}