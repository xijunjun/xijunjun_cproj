#include <iostream>
#include<vector>
using namespace std;

//题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
//根据公式异或运算性质A^B^B^C = A^0^C = A^C，所以直接将数组所有元素异或可得到A^C的值，但是要得到A的值还需要在异或过程中过滤掉C的值。
//A^C的值可以反映A与C的差别，过滤方法：A^C的值中选择bit为1的位作为筛选器，因为A和C在这1位的值一定不同。
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int tp1 = 0;
		for (auto it = data.begin(); it != data.end(); it++)
			tp1 ^= *it;
		int one_bit = 1;
		while (one_bit){
			if ((one_bit&tp1) > 0)break;//注意运算符优先级(one_bit&tp1) > 0和one_bit&tp1 > 0是不同的
			one_bit = one_bit << 1;
		}
		*num1 = 0;
		*num2 = 0;
		for (auto it = data.begin(); it != data.end(); it++)
		{
			if (((*it)&one_bit) > 0)
				(*num1) ^= *it;
			else
				(*num2) ^= *it;
		}

	}
};

int main()
{


	cout << "end" << endl;
	system("pause");
}