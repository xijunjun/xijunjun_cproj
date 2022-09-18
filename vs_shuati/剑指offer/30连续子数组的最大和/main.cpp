#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int max_sum = 0x80000000, cur_sum = 0;
		for (int i = 0; i<array.size(); i++)
		{
			if (cur_sum <= 0)cur_sum = array[i];
			else cur_sum += array[i];
			if (cur_sum>max_sum)max_sum = cur_sum;
		}
		return max_sum;
	}
};

int main()
{
	cout << "end" << endl;
	system("pause");
}