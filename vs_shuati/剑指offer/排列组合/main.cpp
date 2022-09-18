#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


//带重复字符的字符串排列组合
class Solution {
public:
	//
	vector<string> comb(string  inv)//法1：分治合并
	{
		vector<string> res;
		if (inv.size() == 1)return res.push_back(string(inv)), res;
		for (int i = 0; i < inv.size(); i++)
		{
			if (i>0 && inv[i - 1] == inv[i])continue;
			string nexv(inv);
			nexv.erase(nexv.begin() + i);
			vector<string> tmp = comb(nexv);
			for (int j = 0; j < tmp.size(); j++)
				tmp[j].push_back(inv[i]), res.push_back(tmp[j]);
		}
		return res;
	}
	vector<string> Permutation1(string str) {
		sort(str.begin(), str.end());
		return comb(str);
	}
	//法2：遍历第k位的所有可能
	void rPermutation(int k, string cststr, vector<string> &rtvec) {
		if (k == cststr.size() - 1)
			rtvec.push_back(cststr);
		for (int i = k; i < cststr.size(); i++)
		{
			if (i != k && cststr[k] == cststr[i])
				continue;
			swap(cststr[i], cststr[k]);
			rPermutation(k + 1, cststr, rtvec);
		}
	}
	vector<string> Permutation2(string str) {
		vector<string> rtvec;
		sort(str.begin(), str.end());
		rPermutation(0, str, rtvec);
		return rtvec;
	}
};


//数组排列，递归
vector<vector<int>> comb(vector<int>&inv)
{
	vector<vector<int>> res;
	if (inv.size() == 1)return res.push_back(inv), res;
	for (int i = 0; i < inv.size(); i++)
	{
		vector<int>nexv(inv);
		nexv.erase(nexv.begin() + i);
		vector<vector<int>> tmp = comb(nexv);
		for (int j = 0; j < tmp.size(); j++)
		{
			tmp[j].push_back(inv[i]);
			res.push_back(tmp[j]);
		}
	}
	return res;
}
//数组排列，非递归，包含n个数的组合由包含n-1个数的排列组合插空得到
vector<vector<int>> comb(int num)
{
	vector<vector<int>>temp, temp2;
	int lenth = 1;
	temp.push_back(vector<int>(1));
	temp[0][0] = 0;
	vector<vector<int>>*tp1 = &temp, *tp2 = &temp2;
	for (int i = 1; i <= num - 1; i++)//排列组合大循环
	{
		for (int j = 0; j <= lenth - 1; j++)//访问上次所有组合,对每个组合进行扩展
		{
			for (int k = 0; k < i + 1; k++)//每个组合要产生i+1个组合
			{
				vector<int>onev;
				for (int m = 0, n = 0; m <i + 1; m++)
				{
					if (m == k)onev.push_back(i);
					else onev.push_back((*tp1)[j][n++]);
				}
				(*tp2).push_back(onev);
			}
		}
		swap(tp1, tp2);
		(*tp2).clear();
		lenth *= i + 1;
	}
	return (*tp1);
}

int main()
{
	Solution mys;
	vector<string> rtvec = mys.Permutation2("01234567");
	for (int i = 0; i < rtvec.size(); i++)
	{
		cout << rtvec[i] << endl;
	}

	vector<vector<int>> combv = comb(5);
	for (int i = 0; i < combv.size(); i++)
	{
		for (int j = 0; j < combv[i].size(); j++)
		{
			cout << combv[i][j] << ",";
		}
		cout << endl;
	}
	cout << " combv.size():" << combv.size() << endl;

	int table[] = { 0, 1, 2, 3, 4 };
	vector<int>tablev(&table[0], &table[5]);
	vector<vector<int>> combv2 = comb(tablev);
	cout << "-------" << endl;
	for (int i = 0; i < combv2.size(); i++)
	{
		for (int j = 0; j < combv2[i].size(); j++)
		{
			cout << combv2[i][j] << ",";
		}
		cout << endl;
	}
	cout << " combv2.size():" << combv2.size() << endl;

	cout << "end" << endl;
	system("pause");
}