#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty())return 0;
		return Find_min(&rotateArray[0], 0, rotateArray.size() - 1);
	}
	int Find_min(int *a, int start, int end)
	{
		if (start == end)return a[end];
		int mid = (end - start) / 2 + start;
		if (a[mid] > a[end]){
			int n_start;
			if (end - start == 1){
				n_start = mid + 1;
			}
			else{
				n_start = mid;
			}
			return Find_min(a, n_start, end);
		}
		if (a[mid] < a[end]){
			int n_end = mid;
			return Find_min(a, start, n_end);
		}
		if (a[mid] == a[end]){
			for (int i = start; i <= end; i++){
				if (a[i] < a[end])return a[i];
			}
			return a[end];
		}
		cout << "wrong input" << endl;
		return 0;
	}
};
int find_min(int *a,int start,int end)
{
	if (start == end)return a[end];
	int mid = (end - start) / 2 + start;
	if (a[mid] > a[end]){
		int n_start;
		if (end - start == 1){
			n_start = mid + 1;
		}
		else{
			n_start = mid;
		}
		return find_min(a,n_start,end);
	}
	if (a[mid] < a[end]){
		int n_end=mid;
		return find_min(a,start,n_end);
	}
	if (a[mid] == a[end]){
		for (int i = start; i <= end; i++){
			if (a[i] < a[end])return a[i];
		}
		return a[end];
	}
	cout << "wrong input" << endl;
}

int main()
{
	int a[] = {2,3,4,5,6,7,8,9,-2,-1,0,1};
	//int a[] = { 1,1,1,1,1,1,1,1 };
	cout << find_min(a, 0, sizeof(a) / sizeof(int)-1) << endl;
	vector<int>vec_a(&a[0], &a[sizeof(a) / sizeof(int)]);
	Solution mys;
	cout << mys.minNumberInRotateArray(vec_a) << endl;
	cout << "end" << endl;
	system("pause");
} 