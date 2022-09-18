#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//øÏ≈≈
int partition(vector<int>&a,int st,int ed)
{
	int insert_index =st;
	for (int i = st; i < ed;i++)
	{
		if (a[i] <= a[ed])
			swap(a[insert_index++],a[i]);
	}
	swap(a[insert_index],a[ed]);
	return insert_index;
}
void quick_sort(vector<int>&a,int st,int ed)
{
	if (st >= ed)return;
	int pind = partition(a,st,ed);
	quick_sort(a,st,pind-1);
	quick_sort(a, pind + 1, ed); 
}

//πÈ≤¢≈≈–Ú
void merge_sort(vector<int>&a, vector<int>&tmp,int st,int ed)
{
	if (st >= ed)return;
	int mid = (st + ed) / 2;
	merge_sort(a,tmp,st,mid);
	merge_sort(a, tmp, mid+1, ed);
	for (int i = st; i <= ed; i++)
		tmp[i] = a[i];
	int lind = st, rind = mid+1 ;
	for (int i = st; i <= ed; i++)
	{
		if (lind > mid)
			a[i] = tmp[rind++];
		else if (rind > ed)
			a[i] = tmp[lind++];
		else
			a[i] = tmp[lind] < tmp[rind] ? tmp[lind++] : tmp[rind++];
	}
}
//∂—≈≈–Ú
void heap_adj(vector<int>&a,int st,int ed)
{
	if (st >= ed)return;
	int cur = st;
	while (1)
	{
		int next_ind = cur * 2 + 1;
		if (next_ind > ed)break;
		if (next_ind + 1 <= ed&&a[next_ind + 1] > a[next_ind])
			next_ind++;
		if (a[cur] < a[next_ind])
			swap(a[cur], a[next_ind]);
		else
			break;
		cur = next_ind;
	}
}
void heap_sort(vector<int>&a)
{
	int lenth = a.size();
	for (int i = (lenth - 1) / 2; i >= 0; i--)
		heap_adj(a,i,lenth-1);
	for (int i = lenth - 1; i >= 1;i--)
	 {
		swap(a[0],a[i]);
		heap_adj(a,0,i-1);
	}
}
//œ£∂˚≈≈–Ú
void k_adj(vector<int>&a,int k)
{
	int lenth = a.size();
	for (int i = 1; i <= lenth - 1;i++)
	{
		for (int j = i; j - k >= 0;j--)
		{
			if (a[j] < a[j - k])
				swap(a[j],a[j-k]);
			else break;
		}
	}
}
void shell_sort(vector<int>&a)
{
	for (int k = a.size() / 2; k >= 1;k/=2)
	{
		k_adj(a,k);
	}
}

int Add(int num1, int num2)
{
	char* a = reinterpret_cast<char*>(num1);
	return reinterpret_cast<int>(&(a[num2]));
}

int main()
{
	int a[] = {12,3,4,56,34,23,43,58};
	int length = sizeof(a) / sizeof(int);
	vector<int> va(&a[0],&a[length]);
	vector<int>tmp(va);

	quick_sort(va,0,va.size()-1);
	//merge_sort(va,tmp,0,va.size()-1);
	//heap_sort(va);
	//shell_sort(va);
	for (auto it:va)
	{
		cout << it << ",";
	}
	cout << endl;
	cout << Add(-10, -20) << endl;
	system("pause");
}