#include <iostream>
using namespace std;
class Solution1 {//µİ¹éÊµÏÖ 
public:
	int  NumberOf1(int n) {
		unsigned int us_n = n;
		if (n == 0)return 0;
		return(us_n & 1) + NumberOf1(us_n >> 1);
	}
};
class Solution2 {
public:
	int  NumberOf1(int n) {
		unsigned int us_n = n;
		int sum = 0;
		while (us_n != 0)
		{
			if (us_n & 1)sum++;
			us_n = us_n >> 1;
		}
		return sum;
	}
};
class Solution {
public:
	int  NumberOf1(int n) {
		int sum = 0;
		while (n!= 0)
		{
			sum++;
			n = n&(n-1);
		}
		return sum;
	}
};
int main()
{

	Solution mys;
	cout << mys.NumberOf1(-219);
	cout << "end" << endl;
	system("pause");
}