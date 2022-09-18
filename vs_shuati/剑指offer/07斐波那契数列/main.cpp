#include <iostream>
using namespace std;
//µ›πÈ µœ÷
long f_rec(int n)
{
	if (n == 0)return 0;
	if (n == 1)return 1;
	return f_rec(n-1)+f_rec(n-2);
}
long f(int n)
{
	if (n == 0)return 0;
	if (n == 1)return 1;
	int i = 2;
	long fn,fn_1=1, fn_2=0;
	while (i <= n){
		fn = fn_1 + fn_2;
		fn_2 = fn_1;
		fn_1 = fn;
		i++;
	}
	return fn;
}
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)return 0;
		if (n == 1)return 1;
		int i = 2;
		int fn, fn_1 = 1, fn_2 = 0;
		while (i <= n){
			fn = fn_1 + fn_2;
			fn_2 = fn_1;
			fn_1 = fn;
			i++;
		}
		return fn;
	}
};
int main()
{
	Solution mys;
	cout << mys.Fibonacci(5) << endl;
	cout << "end" << endl;
	system("pause");
}