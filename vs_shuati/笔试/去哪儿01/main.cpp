#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>
#include<fstream>
#include<string>
using namespace std;


int func(vector<int>&a,int ind,int &res)
{
	int cnt = 10000;
	if (ind + a[ind] >= res){
		cout << res - ind << " ";
		res = res - ind;
		return 1;
	}
	int tmp,num=0;
	for(int i = 1; i <= a[ind]; i++)
	{
		tmp = 1+func(a, ind+i,res);
		if (tmp < cnt){
			cnt = tmp;
			num = i;
		}
	}
	//cout << num << " ";
	//return max(func(a,ind-));
	return cnt; 
}
vector<string>split_str(string &s, string p)
{
	vector<string>res;
	string subtmp;
	int st = 0, ed = s.size();
	while (1)
	{
		int i = s.find_first_of(p, st);
		if (i == string::npos&&ed == -1)
			break;
		if ((i == string::npos || i == ed) && ed != -1){
			i = ed;
			ed = -1;
		}
		subtmp = s.substr(st, i - st);
		if (!subtmp.empty())
			res.push_back(subtmp);
		st = i + 1;
	}
	return res;
}
int main()
{
	#define CIN myin
	ifstream myin("input.txt");
	string word;
	vector<int>a;
	while (getline(CIN, word))
	{
		vector<string> tmp = split_str(word, " ");
		for (int i = 0; i < tmp.size(); i++)
		a.push_back(stoi(tmp[i]));
	}
	int res = a.size() - 1;
	//func(a, 0,res);
	while (1)
	{
		func(a, 0, res);
		if (res <= 1)break;
	}
	 


	system("pause");
}