#include <iostream>
#include<algorithm>
using namespace std;

//核心思路：递归，非*则正常匹配，遇到x*从0遍历它可能匹配的次数
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		return ismatch(str, pattern, 0, 0);
	}
	bool ismatch(char* s, char* p, int si, int pi)
	{
		if (p[pi] == 0 && s[si] == 0)return true;//两个串同时到底
		if (p[pi] == 0 && s[si] != 0)return false;//p到底，则s必须到底，反之则未必，因为p可能有*
		if (s[si] == 0 && p[pi] != 0 && p[pi + 1] != '*')return false;
		if (p[pi + 1] != '*')//若pi+1不为*，那么直接判断就好了
		{
			if (p[pi] != s[si] && p[pi] != '.')    return false;//若当前的s和p不匹配，则返回false	
			else     return ismatch(s, p, si + 1, pi + 1);
		}
		while (1)//x*是可以匹配任意次的，所以从0往上遍历x*可能匹配的次数
		{
			if (s[si] == 0)    return ismatch(s, p, si, pi + 2);//s到达末尾，返回
			if (p[pi] != s[si] && p[pi] != '.')    return ismatch(s, p, si, pi + 2);//若失配，则p后移两位，继续递归
			if (ismatch(s, p, si, pi + 2))    return true;//一旦后面子串匹配成功就可以返回了
			si++;
		}
	}
};


int main()
{

	Solution mys;
	cout << mys.match("aa",".*b*")<<endl;


	cout << "end" << endl;
	system("pause");
}