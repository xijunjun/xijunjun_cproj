#include <iostream>
#include <string>
#include<vector>
using namespace std;

//简单方法求next数组
int get_max_com(string str)
{
	str.pop_back();
	int lenth = str.size()-1,ed_ind=lenth;
	while (lenth >= 1)
	{
		if (str.substr(0, lenth).compare(str.substr(ed_ind-(lenth-1),lenth)) == 0)
			return lenth;
		lenth--;
	}
	return lenth;
}
vector <int> get_next_simple(string str)
{
	vector<int>next;
	for (int i = 0; i < str.size();i++)
	{
		next.push_back(get_max_com(str.substr(0,i+1)));
	}
	return next;
}
//递推求next
//next数组中新的元素的值一定是
vector <int> get_next(string p)
{
	vector<int>next;
	next.push_back(-1);
	int comp_ind=-1;//comp_ind是当前最长公共前后缀的长度，正好指向了当前最长公共前缀的下一个字符
	for (int i = 0; i < p.size() - 1;i++)
	{
	    while(1)
	   {
			if (comp_ind == -1 || p[i] ==p [comp_ind])
			{
				next.push_back(++comp_ind);
				break;
			}
			else//若比较的字符不相等，减小前缀串
			{
				comp_ind = next[comp_ind];
			}
		}
	}
	return next;
}

//暴力查找算法
vector<int>find_str_index(string s, string p)
{
	vector<int> res;
	int lens=s.size(), lenp=p.size();
	for (int i = 0; i <= lens - lenp;i++)
	{
		int j = 0;
		for (; j < lenp;j++)
		{
			if (p[j] != s[i + j])
			{
				break;
			}
		}
		if (j == lenp)
		{
			res.push_back(i);
		}
	}
	return res;
}

//KMP算法
vector<int>find_str_index_kmp(string s,string p)
{

	vector<int> res;
	vector <int> next=get_next(p);
	int lens = s.size(), lenp = p.size();
	int i = 0, j = 0;
	while (i+j < lens)//当s的索引超出s串时停止循环
	{
		if (p[j] == s[i + j]){
			j++;//一旦匹配成功，模式串的索引便加1
		}
		else{
			 i =i+j-next[j];//如果匹配成功的子串中没有公共前后缀，则s的索引直接跳到i+j，若有公共前后缀的话s的索引再从i+j再向左移动next[j]个单位
			 j = next[j]<0 ? 0 : next[j];//匹配出错过后，更新j的位置，新的j值等于next[j]这指向了前缀的下一个字母，注意next[0]=-1，实际上p还是从0位置开始匹配的，所以此时令j=0
		}
		if (j == lenp-1)//若匹配成功，则记录当前的i位置，然后把p最后一个字符当做匹配失败继续循环
		{
			res.push_back(i);
			i = i + j - next[j];
			j = next[j]<0 ? 0 : next[j];
		}
	}
	return res;
}

//这种写法更易记
vector<int>kmp(string s,string p)
{
	int lp = p.size(), ls = s.size();
	vector<int>res, next = get_next(p);
	if (lp > ls)return res;
	int offj = 0;
	for (int i = 0; i <= ls - lp;)
	{
		int j = offj;
		for (; j <= lp - 1; j++)
		{
			if (p[j] != s[i + j])
				break;
		}
		if (j == lp)
		{
			j--;
			res.push_back(i);
		}
		i = i + j - next[j];
		offj = next[j]>=0?next[j]:0;
	}
	return res;
}


void main()
{
	string str = "ababaaaba";

	//cout << get_max_com("A") << endl;
	//vector <int>next= get_next(str);

	//for (int i = 0; i <next.size();i++)
	//{
	//	cout << next[i] << endl;
	//}
	vector<int> res =kmp(str,"aba");
	for (int i = 0; i <res.size();i++)
	{
		cout << res[i] << endl;
	}
	system("pause");
}