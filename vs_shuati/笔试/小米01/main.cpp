#include <iostream>
#include<vector>
#include <algorithm>
#include <typeinfo>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 1;
		return 0;
	}
	if (n == 1)
	{
		cout << 2;
		return 0;
	}
	int i = 2;
	int fn, fn_1 = 2, fn_2 = 1;
	while (i <= n){
		fn = fn_1 + fn_2;
		fn_2 = fn_1;
		fn_1 = fn;
		i++;
	}
	cout << fn;
	system("pause");
	return 0;
}