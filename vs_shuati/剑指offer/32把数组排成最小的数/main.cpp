#include <iostream>
#include <vector>
#include <string>
using namespace std;

//思路：当数组都是1位数时，直接对数组升序排序再连接起来即可；当数组都是两位或多位数时，同理；
//那么当数组中的位数不同时是否也可以？是可以的。可以这样理解，把位数少的扩展到同样的位数，比如123，9，14，
//把扩展为123，900，140，扩展后最小组合元素的先后顺序并不会发生改变。所以对数组中的按照扩展后的进行比较排序
//即可。
class Solution {
public:
	bool isAsmall(int a, int b)
	{
		string ab, ba;
		return to_string(a) + to_string(b)<to_string(b) + to_string(a);
	}
	int partition(vector<int>&p, int st, int ed)
	{
		swap(p[st], p[ed]);
		int insert_index = st;
		for (int i = st; i <= ed - 1; i++)
		{
			//if (p[i] < p[ed])
			if (isAsmall(p[i], p[ed]))
				swap(p[insert_index++], p[i]);
		}
		swap(p[insert_index], p[ed]);
		return insert_index;
	}
	void quick_sort(vector<int>&p, int st, int ed)
	{
		if (ed <= st)return;
		int index = partition(p, st, ed);
		quick_sort(p, st, index);
		quick_sort(p, index + 1, ed);
	}
	string PrintMinNumber(vector<int> numbers) {
		quick_sort(numbers, 0, numbers.size()-1);
		string rt_str;
		for (int i = 0; i < numbers.size();i++)
		{
			rt_str += to_string(numbers[i]);
		}
		return rt_str;
	}

};


int main()
{
	Solution mys;
	int arr[] = {2,14,3,1,9};
	vector<int>arrrv(&arr[0],&arr[5]);
	//quick_sort(arr, 0, 4);

	cout << mys.PrintMinNumber(arrrv) << endl;

	cout << "end" << endl;
	system("pause");
}