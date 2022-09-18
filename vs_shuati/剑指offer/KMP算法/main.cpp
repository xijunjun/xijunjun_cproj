#include <iostream>
#include <string>
#include<vector>
using namespace std;

//�򵥷�����next����
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
//������next
//next�������µ�Ԫ�ص�ֵһ����
vector <int> get_next(string p)
{
	vector<int>next;
	next.push_back(-1);
	int comp_ind=-1;//comp_ind�ǵ�ǰ�����ǰ��׺�ĳ��ȣ�����ָ���˵�ǰ�����ǰ׺����һ���ַ�
	for (int i = 0; i < p.size() - 1;i++)
	{
	    while(1)
	   {
			if (comp_ind == -1 || p[i] ==p [comp_ind])
			{
				next.push_back(++comp_ind);
				break;
			}
			else//���Ƚϵ��ַ�����ȣ���Сǰ׺��
			{
				comp_ind = next[comp_ind];
			}
		}
	}
	return next;
}

//���������㷨
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

//KMP�㷨
vector<int>find_str_index_kmp(string s,string p)
{

	vector<int> res;
	vector <int> next=get_next(p);
	int lens = s.size(), lenp = p.size();
	int i = 0, j = 0;
	while (i+j < lens)//��s����������s��ʱֹͣѭ��
	{
		if (p[j] == s[i + j]){
			j++;//һ��ƥ��ɹ���ģʽ�����������1
		}
		else{
			 i =i+j-next[j];//���ƥ��ɹ����Ӵ���û�й���ǰ��׺����s������ֱ������i+j�����й���ǰ��׺�Ļ�s�������ٴ�i+j�������ƶ�next[j]����λ
			 j = next[j]<0 ? 0 : next[j];//ƥ�������󣬸���j��λ�ã��µ�jֵ����next[j]��ָ����ǰ׺����һ����ĸ��ע��next[0]=-1��ʵ����p���Ǵ�0λ�ÿ�ʼƥ��ģ����Դ�ʱ��j=0
		}
		if (j == lenp-1)//��ƥ��ɹ������¼��ǰ��iλ�ã�Ȼ���p���һ���ַ�����ƥ��ʧ�ܼ���ѭ��
		{
			res.push_back(i);
			i = i + j - next[j];
			j = next[j]<0 ? 0 : next[j];
		}
	}
	return res;
}

//����д�����׼�
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