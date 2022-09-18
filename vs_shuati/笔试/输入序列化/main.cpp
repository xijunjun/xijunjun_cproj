#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;

//�������Ank
void ank(vector<int>a,int k,int ind,vector<vector<int>>&res)
{
	if (ind == k)
	{
		res.push_back(vector<int>(a.begin(),a.begin()+k));
		return;
	}
	for (int i = ind; i < a.size(); i++)
	{
		swap(a[ind], a[i]);
		ank(a,  k, ind+1,res);
	}
}

//�������Cnk
vector<vector<int>> cnk(vector<int>&a, int k, int st)
{
	vector<vector<int>>res,tmp;
	if (st + k == a.size()){
		return vector<vector<int>>(1, vector<int>(a.begin()+st,a.end()));
	}
	if (k == 1){
		for (int i = st; i <a.size(); i++)
			res.push_back(vector<int>(1,a[i]));
		return res;
	}
	res=cnk(a, k-1, st+1);
	for (int i = 0; i < res.size(); i++)
		res[i].push_back(a[st]);
	tmp = cnk(a, k, st + 1);
	for (auto it : tmp)
		res.push_back(it);
	return res;
}

vector<string>split_str(string &s,string p)
{
	vector<string>res;
	string subtmp;
	int st = 0,ed=s.size();
	while (1)
	{
		int i = s.find_first_of(p, st);
		if (i == string::npos&&ed==-1)
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
//singer_�ܽ� | �ܽ��� | ���»� | ������; song_���� | ������ӭ�� | ������; actor_�ܽ��� | ��ٳ
//�벥���ܽ��׵������������

int main()
{
    #define CIN myin
	ifstream myin("input.txt");
	string s="singer_�ܽ�|�ܽ���|���»�|������;song_����|������ӭ��|������;actor_�ܽ���|��ٳ", s2;

	vector<string>res = split_str(s, ";|_ ");
	for (auto it : res)
		cout << it << endl;

	int t[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	vector<int>a(&t[0], &t[sizeof(t) / sizeof(int)]);
	vector<vector<int>>res2;
	ank(a, 5, 0, res2);
	//res2 = cnk(a, 3, 0);

	for (auto it : res2)
	{
		for (auto it2 : it)
		{
			cout << it2 << ",";
		}
		cout << endl;
	}
	cout << res2.size() << endl;

	vector<int>v(1);
	cout << v.at(1);


	system("pause");
	return 0;
}