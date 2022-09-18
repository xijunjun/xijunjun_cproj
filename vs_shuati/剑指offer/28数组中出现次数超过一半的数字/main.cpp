#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int n = numbers.size();
		if (n == 0) return 0;

		int num = numbers[0], count = 1;
		for (int i = 1; i < n; i++) {
			if (numbers[i] == num) count++;
			else count--;
			if (count == 0) {
				num = numbers[i];
				count = 1;
			}
		}
		// Verifying
		count = 0;
		for (int i = 0; i < n; i++) {
			if (numbers[i] == num) count++;
		}
		if (count * 2 > n) return num;
		return 0;
	}
};

//找出第n/2大的数即可
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int mid = numbers.size() / 2;
		int leftind = 0, rightind = numbers.size()-1, part_index = 0;
		while (1)
		{
			part_index = partition(numbers, leftind, rightind);
			if (part_index < mid)
				leftind = part_index + 1;
			else if (part_index > mid)
				rightind = part_index - 1;
			else
			{
				int count = 0;
				for (int i = 0; i <= numbers.size()-1; i++) 
					if (numbers[i] == numbers[part_index]) count++;
				if (count * 2 > numbers.size()) 
					return numbers[part_index];
				return 0;
			}
		}
	}
	int partition(vector<int>&p, int st, int ed)
	{
		if (ed <= st)return st;
		swap(p[st],p[ed]);
		int insert_index = st;
		for (int i = st; i <= ed - 1; i++)
			if (p[i] <= p[ed])swap(p[i], p[insert_index++]);
		swap(p[insert_index], p[ed]);
		return insert_index;
	}

};


int main()
{
	int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	vector <int>arrvec(arr, arr + sizeof(arr) / sizeof(int));
	Solution mys;
	cout << mys.MoreThanHalfNum_Solution(arrvec);


	cout << "end" << endl;
	system("pause");
}