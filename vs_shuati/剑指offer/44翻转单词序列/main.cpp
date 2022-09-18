#include <iostream>
#include<vector>
#include <string>
using namespace std;

//一个句子分为单词（连续非空格字符）和间隔（连续空格字符）部分，所以只需从后往前遍历，若访问的字符和之前的字符属性（空格和非空格）不同即发生跳变，
//此时往后延1个找到单词或间隔的左边界，同时记录宽度
class Solution {
public:
	string ReverseSentence(string str) {
		string res;
		int lenth = str.size();
		bool is_space = str[lenth-1]==' ';
		int wid = 0;
		for (int i = lenth - 1; i >= 0;i--)
		{
			if (is_space ^ (str[i] == ' '))
				wid++;
			else//遇到跳变则完成
			{
				res += string(str.substr(i+1,wid));
				is_space = 1-is_space;
				wid = 1;
			}
		}
		res += string(str.substr(0, wid));
		return res;
	}
};

int main()
{
	Solution mys;

	string a = "i am a boy  ";

	cout << mys.ReverseSentence(a) << endl;

	cout << "end" << endl;
	system("pause");
}