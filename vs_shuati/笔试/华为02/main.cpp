#include<iostream>
#include <stack>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
bool ismatch22(string s1, string s2)
{
	int len = s2.size();
	string p1, p2;
	int hash[256] = { 0 };
	for (int i = 0; i<len; i++)
	{
		if (hash[s2[i]] == 0)
			hash[s2[i]] = i+1;
	}

	char hash2[256] = { 0 };
	for (int i = 0; i<len; i++)
	{
		//if (hash[s1[i]] == 0){
		//	hash2[256]=s2[hash[s1[i]] - 1]
		//}
		//	s1[i] = s2[hash[s1[i]]-1];
	}
	return s1 == s2;
}
//bool ismatch(string s1, string s2)
//{
//	int len = s2.size();
//	string p1, p2;
//	vector<vector<bool>>mat1,mat2;
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = 0; j < len; j++)
//		{
//			if (s1[i] == s1[j] ^ s2[i] == s2[j])
//				return false;
//		}
//	}
//	return true;
//}
bool ismatch(string &s1, string &s2, int st)
{
	int len = s2.size();
	for (int i = 0; i <= len/2; i++)
	{
		for (int j = 0; j <= len/2; j++)
		{
			if ((s1[st + i] == s1[st + j] ^ s2[i] == s2[j])||(s1[st +len-i-1] == s1[st + len-j-1] ^ s2[len-i-1] == s2[len-j-1]))
				return false;
		}
	}
	if ((len % 2) && (s1[st + len / 2] == s1[st + len / 2] ^ s2[len / 2] == s2[len / 2]))
		return false;
	return true;
}
int solve2(string S, string T) {
	int len1 = S.size(), len2 = T.size();
	int cnt = 0;
	for (int i = 0; i <= len1 - len2; i++)
	{
		if (ismatch(S, T, i))
			cnt++;
	}
	return cnt;
}

int solve(string S, string T) {
	int len1 = S.size(), len2 = T.size();
	int cnt = 0;
	for (int i = 0; i <= len1 - len2; i++)
	{
		if (ismatch(S, T, i))
			cnt++;
	}
	return cnt;
}
int main()
{
	string s2 = "aba", s1 = "ababcb";
	cout << solve(s1, s2);

	system("pause");
}
