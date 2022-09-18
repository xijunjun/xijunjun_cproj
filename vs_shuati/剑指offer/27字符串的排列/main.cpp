#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//打印字符串的排列组合
class Solution0 {
public:

	void Permutation(string headstr, string cststr) {
		for (int i = 0; i < cststr.size(); i++)
		{
			string head(headstr), str(cststr);
			head.push_back(cststr[i]);
			str.erase(str.begin() + i);
			if (str.size() == 0)
				cout << head << endl;
			Permutation(head, str);
		}

	}
};
//打印去重过后的字符串组合
class Solution1 {
public:
	
	 void Permutation(string headstr,string cststr) {
		string onlystr;
		for (int i = 0; i < cststr.size(); i++)
		{
			 bool isnew=1;
			 for (int j = 0; j < onlystr.size(); j++)
			 {
				 if (cststr[i] == onlystr[j])
				 {
					 isnew = 0;
					 break;
				 }
			 }
			if (isnew == 0)continue;
			onlystr.push_back(cststr[i]);
			string head(headstr);
			string str(cststr);
			head.push_back(cststr[i]);
			string::iterator it;
			it = str.begin() + i;
			str.erase(it);
			if (str.size() == 0)
				cout << head<<endl;
			Permutation(head,str);
		}
		
	}
};


//f(abc)={a+f(bc),b+f(ac),c+f(ab)}
class Solution11 {
public:
	vector<string> rPermutation(string combstr, string cststr) {
		string onlystr;
		vector<string> rtvec;
		for (int i = 0; i < cststr.size(); i++)
		{
			size_t found;
			found = onlystr.find(cststr[i]);
			if (found != string::npos)
				continue;
			onlystr.push_back(cststr[i]);
			string head(combstr), str(cststr);
			head.push_back(cststr[i]);
			str.erase(str.begin() + i);
			if (str.size() == 0)
				rtvec.push_back(head);
			vector<string> tpvec = rPermutation(head, str);
			rtvec.insert(rtvec.end(), tpvec.begin(), tpvec.end());
		}
		return rtvec;
	}
	vector<string> Permutation(string str) {
		return rPermutation("", str);
	}
};


//
class Solution {
public:
	vector<string> comb(string  inv)//更简洁的递归实现
	{
		vector<string> res;
		if (inv.size() == 1)return res.push_back(string(inv)), res;
		for (int i = 0; i < inv.size(); i++)
		{
			string nexv(inv);
			nexv.erase(nexv.begin() + i);
			vector<string> tmp = comb(nexv);
			for (int j = 0; j < tmp.size(); j++)
				tmp[j].push_back(inv[i]),res.push_back(tmp[j]);
		}
		return res;
	}
	void rPermutation(int k, string &cststr, vector<string> &rtvec) {//遍历第k位的所有可能
		if (k == cststr.size() - 1)
			rtvec.push_back(cststr);
		for (int i = k; i < cststr.size(); i++)
		{
			if (i != k && cststr[k] == cststr[i])
				continue;
			swap(cststr[i], cststr[k]);
			rPermutation(k + 1, cststr, rtvec);
			swap(cststr[i], cststr[k]);
		}
	}
	vector<string> Permutation(string str) {
		vector<string> rtvec;
		sort(str.begin(), str.end());
		rPermutation(0, str, rtvec);
		return rtvec;
	}
};
int main()
{
	Solution mys;
	vector<string> rtvec = mys.Permutation("1123");
	for (int i = 0; i < rtvec.size(); i++)
	{
		cout << rtvec[i] << endl;
	}

	cout << "end" << endl;
	system("pause");
}