#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
using namespace std;

int PartSort(int* array, int left, int right)
{
	int& key = array[right];
	while (left < right)
	{
		while (left < right && array[left] <= key)
		{
			++left;
		}
		while (left < right && array[right] >= key)
		{
			--right;
		}
		swap(array[left], array[right]);
	}
	swap(array[left], key);
	return left;
}
void QuickSort(int* array, int left, int right)
{
	//assert(array);
	if (left >= right)//表示已经完成一个组
	{
		return;
	}
	int index = PartSort(array, left, right);//枢轴的位置
	for (int i = 0; i < 8; i++)
		cout << array[i] << ",";
	cout << endl;
	QuickSort(array, left, index - 1);
	QuickSort(array, index + 1, right);
}


//快排
int partition(vector<int>&a, int st, int ed)
{
	int insert_index = st;
	//swap(a[st], a[ed]);
	for (int i = st; i < ed; i++)
	{
		if (a[i] <= a[ed])
			swap(a[insert_index++], a[i]);
	}
	swap(a[insert_index], a[ed]);
	return insert_index;
}
void quick_sort(vector<int>&a, int st, int ed)
{
	if (st >= ed)return;
	int pind = partition(a, st, ed);
	for (int i = 0; i < 8; i++)
		cout << a[i] << ",";
	cout << endl;
	quick_sort(a, st, pind-1);
	quick_sort(a, pind + 1, ed);
}
int main()
{
	int a[] = {2,8,7,1,3,5,6,4};
	int n = sizeof(a) / sizeof(int);
	vector<int>va(&a[0],&a[n]);
	//quick_sort(va, 0, n - 1);
 
	QuickSort(a, 0, n - 1);

	for (int i = 0; i < 8; i++)
		cout<<a[i]<<",";

	cout << endl;
	int *aa[3];
	cout << sizeof(aa);
	system("pause");
	return 0;
}