#include <iostream>
#include<vector>
using namespace std;
//递归版本
class Solution2 {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() == 0)return 0;
		int lindex = find_lindex(k, data, 0, data.size() - 1);
		if (lindex == -1)return 0;
		int rindex = find_rindex(k, data, 0, data.size() - 1);
		return rindex - lindex + 1;
	}
	int find_lindex(int num, vector<int> &data, int st, int ed)
	{
		if ((ed == st) && (data[st] != num))return -1;
		int mid = (st + ed) / 2;
		if (data[mid] == num)
		{
			if (mid - 1 >= st&&data[mid - 1] == num)
				return find_lindex(num, data, st, mid - 1);
			return mid;
		}
		if (data[mid] > num)
			return find_lindex(num, data, st, mid - 1);
		else
			return find_lindex(num, data, mid + 1, ed);
	}
	int find_rindex(int num, vector<int> &data, int st, int ed)
	{
		if ((ed == st) && (data[st] != num))return -1;
		int mid = (st + ed) / 2;
		if (data[mid] == num)
		{
			if (mid + 1 <= ed&&data[mid + 1] == num)
				return find_rindex(num, data, mid + 1, ed);
			return mid;
		}
		if (data[mid] > num)
			return find_rindex(num, data, st, mid - 1);
		else
			return find_rindex(num, data, mid + 1, ed);
	}
};


//循环版本
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() == 0)return 0;
		int lindex = find_lindex(k, data);
		if (lindex == -1)return 0;
		int rindex = find_rindex(k, data);
		return rindex - lindex + 1;
	}

	//1.找到的情况   2.找不到的情况  3.二分搜索的情况                                                                             
	int find_lindex(int num, vector<int> &data)
	{
		int left = 0, right = data.size() - 1;
		while (1)
		{
			int mid = (left + right) / 2;
			if (left == right)//若最后没找到
				return data[left] == num ? left : -1;
			if ((data[mid] == num&&mid - 1 >= left&&data[mid - 1] != num) || (data[mid] == num&&mid == left))
				return mid;
			if (data[mid] < num)
				left = mid + 1;
			else //砍掉右边数组有两种情况，第一：该位置大于num，第二该位置等于num并且该位置左边的位置也等于num
				right = mid - 1;
		}
	}
	int find_rindex(int num, vector<int> &data)
	{
		int left = 0, right = data.size() - 1;
		while (1)
		{
			int mid = (left + right) / 2;
			if (left == right)//当只剩1个元素时可以直接判断了
				return data[left] == num ? left : -1;
			//两种情况可以返回，1、该位置的值等于num并且该位置右边的值不为num 2、该位置的值等于并且该位置已经到达最右端
			if ((data[mid] == num&&mid + 1 <= right&&data[mid + 1] != num) || (data[mid] == num&&mid == right))
				return mid;
			if (data[mid] > num)
				right = mid - 1;
			else //砍掉左边数组有两种情况，第一：该位置小于num，第二该位置等于num并且该位置右边的位置也等于num
				left = mid + 1;
		}
	}
};



int main()
{
	int a[] = {1,2,3,4,5,6,6,6,6,6,6,6,6,6,6,6,7,8,9,10};
	Solution mys;

	vector<int>va(&a[0],&a[sizeof(a)/sizeof(int)]);


	cout << mys.GetNumberOfK(va,6) << endl;


	cout << "end" << endl;
	system("pause");
}