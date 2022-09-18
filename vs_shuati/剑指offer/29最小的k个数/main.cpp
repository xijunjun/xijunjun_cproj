#include <iostream>
#include<vector>
using namespace std;

//求数组topk小(大)的数


//基于partition,时间复杂度O(n),此方法要求输入数据是可更改的变量
class Solution1 {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector <int>rt;
		if (k > input.size() || k <= 0)return rt;

		int tpst = 0, tped = input.size() - 1;
		while (1)
		{
			int curind = partition(input, tpst, tped);
			if (curind < k-1)//注意是k-1!不是k
				tpst = curind + 1;
			else if (curind > k-1)
				tped = curind - 1;
			else
				break;
		}
		rt = vector <int>(input.begin(), input.begin() + k);
		return rt;
	}
	int partition(vector<int> &p, int st, int ed)
	{
		if (ed < st)return -1;
		int insert_index = st;
		swap(p[st], p[ed]);
		for (int i = st; i <= ed - 1; i++)
		if (p[i] < p[ed])swap(p[i], p[insert_index++]);
		swap(p[ed], p[insert_index]);
		return insert_index;
	}
};


//基于大顶堆,时间复杂度O(nlogk),但不要求数据是可修改的，在处理海量数据时此方法更好
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		
		if (k <= 0 || k > input.size())return vector<int>();
		vector<int>tmp(input.begin(), input.begin()+k);
		heap_adj(tmp, 0,k);
		for (int i = k; i < input.size();i++)
		{
			if (input[i] < tmp[0])
			{
				tmp[0] = input[i];
				heap_adj(tmp, 0, k);
			}
		}
		return tmp;
	}
	void heap_adj(vector<int>&p, int root, int lenth)
	{
		int nexind;
		while (1)
		{
			nexind = root * 2 + 1;
			if (nexind > lenth - 1)break;
			if (nexind + 1 < lenth&&p[nexind + 1] > p[nexind])
				nexind++;
			if (p[nexind]>p[root])swap(p[nexind], p[root]);
			else break;
			root = nexind;
		}
	}
};

//void heap_sort(int *p,  int lenth)
//{
//	for (int i = (lenth - 1) / 2; i >= 0;i--)
//	{
//		heap_adj(p, i, lenth);
//	}
//	for (int i = lenth - 1; i > 0; i--)
//	{
//		swap(p[i],p[0]);
//		heap_adj(p, 0, i);
//	}
//}


int main()
{
	int arr[] = { 1,4,2,0,5,9,8,7};
	int lenth = sizeof(arr) / sizeof(int);
	Solution mys;
	//mys.sort_topk_small(arr, 0, lenth - 1,4);

	vector<int>arrv(&arr[0],&arr[lenth]);

	cout << lenth << endl;

	vector<int> out = mys.GetLeastNumbers_Solution(arrv,0);


	//heap_sort(arr, lenth);

	for (int i = 0; i < arrv.size(); i++)
	{
		cout << arrv[i] << ',';
	}

	cout << "end" << endl;
	system("pause");
}