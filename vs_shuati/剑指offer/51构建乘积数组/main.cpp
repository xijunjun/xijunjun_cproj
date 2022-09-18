#include <iostream>
#include<vector>
using namespace std;



//使用两个数组保存中间结果，通过查表得到结果
class Solution1 {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> res;
		int *p1 = new int[A.size()];
		int *p2 = new int[A.size()];
		p1[0] = A[0];
		p2[A.size() - 1] = A[A.size() - 1];
		for (int i = 1; i <= A.size() - 1; i++)
		{
			p1[i] = p1[i - 1] * A[i];
		}
		for (int i = A.size() - 2; i >= 0; i--)
		{
			p2[i] = p2[i + 1] * A[i];
		}
		res.push_back(p2[1]);
		for (int i = 1; i <= A.size() - 2; i++)
		{
			res.push_back(p1[i - 1] * p2[i + 1]);
		}
		res.push_back(p1[A.size() - 1 - 1]);
		return res;
	}
};
//Solution1的改进，减少了一个数组的使用，只记录从后往前的数组,在从左往右的过程中陆续得出结果
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> res;
		int l = A.size();
		int *p = new int[l];
		p[l - 1] = A[l - 1];
		for (int i = l - 2; i >= 0; i--)
		{
			p[i] = p[i + 1] * A[i];
		}
		res.push_back(p[1]);
		int leftmul = A[0];
		for (int i = 1; i <= l - 2; i++)
		{
			res.push_back(leftmul*p[i + 1]);
			leftmul *= A[i];
		}
		res.push_back(leftmul);
		return res;
	}
};
int main()
{
	cout << "end" << endl;
	system("pause");
}