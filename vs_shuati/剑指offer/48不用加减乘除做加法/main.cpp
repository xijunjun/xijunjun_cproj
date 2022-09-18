#include <iostream>
using namespace std;
#include<vector>
//将加法分解为  半加运算结果+进位运算结果，异或是半加运算，与运算再向左移一位是进位运算
//注意这里的jinwei(num2）为什么最终会变为0？这是由于每次递归都会(num1&num2) << 1;也就是说即使num2迟早会被0从右向左填满。
class Solution1 {
public:
	int Add(int num1, int num2)
	{
		int half_sum = num1^num2;
		int jinwei = (num1&num2) << 1;
		if (jinwei == 0)
			return half_sum;
		else return Add(half_sum, jinwei);
	}
};
//现将num1转换为指针a，再求a[num2]的地址
class Solution {
public:
	int Add(int num1, int num2)
	{
		char* a = reinterpret_cast<char*>(num1);
		return reinterpret_cast<long>(&(a[num2]));
	}
};

int main()
{
	//vector<int> dict(256,-1);
	cout << "end" << endl;
	system("pause");
}