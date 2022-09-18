#include <iostream>
using namespace std;


class Solution {
public:
	int jumpFloor(int number) {
		if (number == 0)return 0;
		if (number == 1)return 1;

		return pow(2,number-1);
	}
};
int main()
{
	Solution mys;
	cout << mys.jumpFloor(5) << endl;
	cout << "end" << endl;
	system("pause");
}