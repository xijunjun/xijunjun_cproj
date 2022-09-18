#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;

typedef struct
{
	int weight;
	int parent, left, right;
}Node;
pair<int, int> Select(vector<Node>& HuffTree, int n)
{
	int s1, s2;
	for (int i = 1; i <= n; i++)
	if (HuffTree[i].parent == 0){
		s1 = i;
		break;
	}
	for (int i = 1; i <= n; i++)
	if (HuffTree[i].weight < HuffTree[s1].weight && HuffTree[i].parent == 0)
		s1 = i;
	for (int i = 1; i <= n; i++)
	if (HuffTree[i].parent == 0 && i != s1){
		s2 = i;
		break;
	}
	for (int i = 1; i <= n; i++)
	if (HuffTree[i].weight < HuffTree[s2].weight && HuffTree[i].parent == 0 && i != s1)
		s2 = i;
	return make_pair(s1, s2);
}

void GenTree(vector<Node> &HuffTree, int n, vector<int>&wei)
{
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	for (int i = 1; i <= m; ++i)
	{
		HuffTree[i].parent = 0; HuffTree[i].left = 0; HuffTree[i].right = 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		HuffTree[i].weight = wei[i - 1];
	}
	for (int i = n + 1; i <= m; ++i)
	{
		pair<int, int>tmp;
		tmp = Select(HuffTree, i - 1);
		HuffTree[tmp.first].parent = i;
		HuffTree[tmp.second].parent = i;
		HuffTree[i].left = tmp.first;
		HuffTree[i].right = tmp.second;
		HuffTree[i].weight = HuffTree[tmp.first].weight + HuffTree[tmp.second].weight;
	}
}

map<char, string> GEnCode(vector<Node> HuffTree, string s1, int n)
{
	map<char, string>hc;
	string cd(n, 0);
	for (int i = 1; i <= n; i++)
	{
		int start = n - 1;
		int c = i;
		int f = HuffTree[c].parent;
		while (f != 0)
		{
			--start;
			if (HuffTree[f].left == c) cd[start] = '0';
			else cd[start] = '1';
			c = f;
			f = HuffTree[f].parent;
		}
		hc[s1[i - 1]] = string(&cd[start]);
	}
	return hc;
}
string EnCode(string s, map<char, string>&hc)
{
	string  res;
	for (auto it : s)
	{
		res += hc[it];
	}
	return res;
}
int main()
{
#define CIN myin
	ifstream myin("input.txt");
	string s, s1;
	CIN >> s;
	int hash[256] = {};
	for (int i = 0; i < s.size(); i++)
	{
		hash[s[i]]++;
		if (hash[s[i]] == 1)
		{
			s1.push_back(s[i]);
		}
	}
	vector<int>wei;
	for (int i = 0; i < s1.size(); i++)
	{
		wei.push_back(hash[s1[i]]);
	}
	int num = s1.size();
	vector<Node>HuffTree(2 * num);

	GenTree(HuffTree, num, wei);
	map<char, string>hc = GEnCode(HuffTree, s1, num);
	cout << EnCode(s, hc);
	system("pause");
	return 0;
}