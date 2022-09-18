#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string BigNumMul(string s1,string s2)
{
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(), s2.end());
	int len1 = s1.size(), len2 = s2.size();
	vector<int>num(len1+len2,0);
	for (int i = 0; i < len1; i++)
		for (int j = 0; j < len2;j++)
			num[i + j]+= (s1[i] - '0')*(s2[j] - '0');
	string res = "";
	for (int i = 1; i < len1 + len2; i++){
		num[i]+= num[i - 1] / 10;
		num[i - 1]%=10 ;
	}
	int i = len1 + len2 - 1;
	for (; i >= 1; i--)
		if (num[i])break;
	for (; i >=0; i--)
		res += to_string(num[i]);
	return res;
}
string BigNumMinus(string s1, string s2)
{
	if (s1<s2)swap(s1, s2);
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int len1 = s1.size(), len2 = s2.size();
	vector<int>num(len1, 0);
	for (int i = 0; i < len1; i++)
		num[i] = s1[i] - '0';
	for (int j = 0; j < len2; j++)
	{
		int num2 = s2[j] - '0';
		if (num[j] <num2)
		{
			num[j] = num[j] + 10 - num2;
			num[j + 1] -= 1;
		}
		else num[j] = num[j] - num2;
	}
	string res = "";
	int i = len1 - 1;
	for (; i >= 1; i--)
		if (num[i])break;
	for (; i >= 0; i--)
		res += to_string(num[i]);
	return res;
}
int main()
{
	cout << BigNumMinus("123456789", "123450000") << endl;
	cout << "end" << endl;
	system("pause");
}