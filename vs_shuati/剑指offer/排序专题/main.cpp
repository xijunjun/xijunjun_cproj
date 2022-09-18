#include <iostream>
#include<vector>
#include <algorithm>
#include <typeinfo>
using namespace std;

//01冒泡排序
void bubble_sort(int*input, int st, int ed)
{
	int lenth = ed - st + 1;
	for (int rindex = int(lenth - 1); rindex >= st; rindex--)//大循环，确定右界
	{
		for (int j = 0; j <= rindex-1; j++)//相邻数比较
		{
			if (input[j + 1]<input[j])
				swap(input[j], input[j + 1]);
		}
	}
}

//02选择排序
void select_sort(int*input, int st, int ed)
{
	int lenth = ed - st + 1;
	for (int lindex = st; lindex <= int(lenth - 2); lindex++)//大循环，确定左界
	{
		int  minindex = lindex;
		for (int j = lindex; j <= lenth - 1; j++)//寻找数组左界到最右的最小值，
		if (input[j] < input[minindex])
			minindex = j;
		swap(input[lindex], input[minindex]);
	}
}

//03插入排序
void insert_sort(int*input, int st, int ed)
{
	int lenth = ed - st + 1;
	for (int lindex = st - 1; lindex <= int(lenth - 1); lindex++)//大循环，确定左界
	{
		for (int j = lindex; j >= 1; j--)//相邻数比较
		{
			if (input[j - 1] > input[j])
				swap(input[j - 1], input[j]);
			else
				break;
		}
	}
}

//04归并排序
void merge_sort(int *input, int*temp, int st, int ed)
{
	if (ed <= st)return;
	int midindex = (st + ed) / 2;
	merge_sort(input, temp, st, midindex);
	merge_sort(input, temp, midindex + 1, ed);
	for (int i = st; i <= ed; i++)//暂存分治排序过后的结果
		temp[i] = input[i];
	int lind = st, rind = midindex + 1;
	for (int i = st; i <= ed; i++)//合并有序数组
	{
		if (lind <= midindex&&rind <= ed)//若两个子数组都没访问完
			input[i] = temp[lind] < temp[rind] ? temp[lind++] : temp[rind++];
		else if (lind <= midindex)//若只剩左边的数组
			input[i] = temp[lind++];
		else if (rind <= ed)//若只剩右边的数组
			input[i] = temp[rind++];
	}
}

//05快速排序
void quick_sort(int*input, int st, int ed)
{
	if (ed <= st)return;
	swap(input[st], input[ed]);
	int insert_index = st - 1;
	for (int i = st; i <= ed - 1; i++)
	if (input[i] < input[ed])
		swap(input[++insert_index], input[i]);
	swap(input[++insert_index], input[ed]);
	quick_sort(input, st, insert_index);
	quick_sort(input, insert_index + 1, ed);
}

int partition(int *p, int st, int ed)
{
	//swap(p[st], p[ed]);
	int insert_index = st;
	for (int i = st; i <= ed - 1; i++)
		if (p[i] < p[ed])swap(p[insert_index++], p[i]);
	swap(p[insert_index], p[ed]);
	return insert_index;
}
void quick_sort_par(int *p, int st, int ed)
{
	if (ed <= st)return;
	int index = partition(p, st, ed);
	quick_sort(p, st, index);
	quick_sort(p, index + 1, ed);
}




//06堆排序
//https://www.cnblogs.com/chengxiao/p/6129630.html
//堆排序不开辟额外的内存，将数组的索引与堆对应起来，将数组看成一个逻辑结构上的堆，由于是完全二叉树，所以有几个特性，索引为s的节点的左子节点为2*s+1,
//叶节点的数量和与非叶节点数量相等或多1个，记数组总长度为lenth，则非叶节点有lenth/2个。
//第一步是构造大顶堆，总体思路是从下往上、从右往左去对非叶节点及其子树进行调整，每次调整保证该节点及其子树成为大顶堆，
//对于1次调整过程，具体的做法是将该节点与子节点中大的值进行交换，直到访问到叶节点。
void heap_adj(int*input, int rootind, int maxind)
{
	while (1)
	{
		int nextind = rootind * 2 + 1;//计算源节点的左子节点
		if (nextind > maxind)break;//若左子节点超出范围，退出
		if (nextind + 1 <= maxind&&input[nextind + 1] > input[nextind])//nexind指向较大的子节点
			nextind++;
		if (input[rootind] >= input[nextind])break;//若源节点大于子节点则退出，因为是从下往上、从右往左去对非叶节点及其子树进行调整，所以子树已经是大顶堆。
		swap(input[rootind], input[nextind]);//源节点大于子节点则交换
		rootind = nextind;
	}
}
void heap_sort(int*input, int st, int ed)
{
	int lenth = ed - st + 1;
	for (int i = lenth / 2 - 1; i >= st; i--)//此循环负责构造大顶堆
	{
		heap_adj(input, i, lenth - 1);
	}
	for (int i = lenth - 1; i >= st; i--)//依次确定从lenth-1到st的值
	{
		swap(input[0], input[i]);//把堆顶值与当前待定节点值互换
		heap_adj(input, 0, i - 1);//调整子堆为大顶堆，大于i的节点不参与调整
	}
}

//07希尔排序
//与插入排序的简单策略不同，shell排序通过多个层次的插入排序提高效率，
void shell_sort(int*input, int st, int ed)
{
	int lenth = ed - st + 1;
	for (int step = lenth; step >= 1; step = step / 2)
	{
		for (int i = 0; i <= lenth - 1; i++)
		{
			for (int j = i; j - step >= 0; j -= step)
			{
				if (input[j] < input[j - step])
					swap(input[j], input[j - step]);
			}
		}
	}
}

//08计数排序
void countingsort(int*input, int st, int ed)
{
	int lenth = ed - st + 1;
	auto minmax = minmax_element(input+st,input+ed+1);
	int min = *minmax.first, max = *minmax.second;
	int *p_counts = new int[max - min + 1];//构造计数数组，数组序号为ind处的值代表源数组中值为min+ind的元素的个数
	memset(p_counts, 0, (max - min + 1)*sizeof(int) / sizeof(char));
	for (int i = 0; i <= lenth - 1; i++)//执行计数
		p_counts[input[i] - min]++;
	for (int i = 0, ind = 0; i <= max - min + 1 - 1; i++)//遍历计数数组
	while (p_counts[i]--)
		input[ind++] = min + i;
	delete[]p_counts;
}
void CntSort(vector<int>&a)
{
	int ind=0,maxnum = *max_element(a.begin(),a.end());
	vector<int>hash(maxnum+1,0);
	for (int i = 0; i < a.size(); i++)
		hash[a[i]]++;
	for (int i = 0; i <= maxnum;i++)
		while (hash[i]--)
			a[ind++] = i;
}

void i_sort(vector<int>&a)
{
	for (int i = 1; i <=int(a.size() - 1); i++)
	{
		for (int j = i; j >= 1;j--)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
			else
				break;
		}
	}
}
int main()
{
	int arr[] = { 54, 35, 48, 36, 27, 12, 44, 44, 8, 14, 26, 17, 28 };
	
	//int arr[] = { 4 };

	int lenth = sizeof(arr) / sizeof(int);
	int *ptemp = new int[lenth];
	vector<int>a(&arr[0],&arr[lenth]);

	//bubble_sort(arr, 0, lenth - 1);
	//select_sort(arr, 0, lenth - 1);
	//insert_sort(arr, 0,lenth-1);
	//merge_sort(arr, ptemp, 0, lenth - 1);
	//quick_sort(arr, 0, lenth - 1);
	//quick_sort_par(arr, 0, lenth - 1);

	//heap_sort(arr, 0, lenth - 1);
	//shell_sort(arr, 0, lenth - 1);
	//countingsort(arr, 0, lenth - 1);
	CntSort(a);

	for (int i = 0; i<a.size(); i++)
	{
		cout << a[i] << ",";
	}


	cout << endl << "vector sort:" << endl;

	i_sort(a);
	for (int i = 0; i<a.size(); i++)
	{
		cout << a[i] << ",";
	}

	cout << endl << "end" << endl;
	int kk = 0;
	vector<int>test;
	cout << (kk>int(test.size() - 1)) << endl;
	delete[]ptemp;
	system("pause");
}