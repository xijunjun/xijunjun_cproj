#include <iostream>
using namespace std;


class Solution {
public:
	int rectCover(int number) {
		if (number == 0)return 0;
		if (number == 1)return 1;
		if (number == 2)return 2;
		int i = 3;
		int fn, fn_1 = 2, fn_2 = 1;
		while (i <= number){
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
	cout << mys.rectCover(5) << endl;
	cout << "end" << endl;
	system("pause");
}