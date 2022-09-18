#include <iostream>
#include<string>
using namespace std;

//简单写法
class Solution2 {
public:
	string LeftRotateString(string str, int n) {
		string res;
		if (str.size() == 0)
			return res;
		n = n%str.size();
		for (int i = n; i < str.size(); i++)
		{
			res.push_back(str[i]);
		}
		for (int i = 0; i < n; i++)
		{
			res.push_back(str[i]);
		}
		return res;
	}
};
//技巧写法
class Solution {
public:
	string LeftRotateString(string str, int n) {
		int lenth = str.size();
		if (lenth == 0)return str;
		str += str;
		n = n%lenth;
		return str.substr(n,lenth);
	}
};


int main()
{
	Solution mys;
	string a = "12345";
	cout << mys.LeftRotateString(a,0)<<endl;


	cout << "end" << endl;
	system("pause");
}