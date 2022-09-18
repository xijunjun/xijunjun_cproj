#include <iostream>
using namespace std;

class Solution1 {//递归实现
public:
	double Power(double base, int exponent) {
		if (base == 0)return 0;
		if (exponent == 0)return 1;
		if (exponent > 0)return base*Power(base, exponent - 1);
		else return 1.0 / base*Power(base, exponent + 1);
	}
};
class Solution2 {//循环实现
public:
	double Power(double base, int exponent) {
		if (base == 0)return 0;
		if (exponent == 0)return 1;
		int minu = -1;
		if (exponent < 0){ minu = +1; base = 1.0 / base; }
		double result = 1.0;
		while (exponent != 0)
		{
			result *= base;
			exponent += minu;
		}
		return result;
	}
};
class Solution {//高效的递归实现
public:
	double Power(double base, int exponent) {
		if (base == 0)return 0;
		if (exponent == 0)return 1;
		int minu = -1;
		if (exponent < 0){ minu = +1; base = 1.0 / base; }
		return Power_un(base, exponent, minu);
	}
	double Power_un(double base, int exponent, int minu) {
		if (exponent == 0)return 1;
		if (exponent & 1){
			double halfresult = Power_un(base, (exponent + minu)>>1, minu);
			return base*halfresult*halfresult;
		}
		else{
			double halfresult = Power_un(base, exponent>>1, minu);
			return halfresult*halfresult;
		}
	}
};
int main()
{
	Solution mys;
	cout << mys.Power(0.5,-3);
	cout << "end" << endl;
	system("pause");
}