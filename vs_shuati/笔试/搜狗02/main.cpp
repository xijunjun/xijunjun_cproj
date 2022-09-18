#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;

//排列组合Ank
void ank(vector<int>a, int k, int ind, vector<vector<int>>&res)
{
	if (ind == k)
	{
		res.push_back(vector<int>(a.begin(), a.begin() + k));
		return;
	}
	for (int i = ind; i < a.size(); i++)
	{
		swap(a[ind], a[i]);
		ank(a, k, ind + 1, res);
	}
}

//排列组合Cnk
vector<vector<int>> cnk(vector<int>&a, int k, int st)
{
	vector<vector<int>>res, tmp;
	if (st + k == a.size()){
		return vector<vector<int>>(1, vector<int>(a.begin() + st, a.end()));
	}
	if (k == 1){
		for (int i = st; i <a.size(); i++)
			res.push_back(vector<int>(1, a[i]));
		return res;
	}
	res = cnk(a, k - 1, st + 1);
	for (int i = 0; i < res.size(); i++)
		res[i].push_back(a[st]);
	tmp = cnk(a, k, st + 1);
	for (auto it : tmp)
		res.push_back(it);
	return res;
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
//singer_周杰 | 周杰伦 | 刘德华 | 王力宏; song_冰雨 | 北京欢迎你 | 七里香; actor_周杰伦 | 孙俪
//请播放周杰伦的七里香给我听

int main()
{
	#define CIN myin
	ifstream myin("input.txt");
	int N;
	CIN >> N;
	vector<int>a(N);
	for (int i = 0; i < N;i++)
		CIN >> a[i];
	int maxnum = *max_element(a.begin(),a.end());



	for (int i = 0; i < N; i++)
		a.push_back(a[i]);

	int mindis = 0x7fffffff;
	for (int i = 0; i < N; i++)
	{
		if (a[i] != maxnum)continue;
		int st = i, ed = i + N - 1;
		int sum1 = 0, sum2 = 0;
		while (1)
		{
			if (st>ed)break;
			sum1 += a[st]>=a[ed] ? a[st++] : a[ed--];
			if (st>ed)break;
			sum2 += a[st]>=a[ed] ? a[st++] : a[ed--];
		}
		if (abs(sum1 - sum2) < mindis)
			mindis = abs(sum1 - sum2);
	}

	cout << mindis;


	system("pause");
	return 0;
}