#include <iostream>
#include<vector>
using namespace std;

//
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum)
	{
		vector<int>res;
		int lind = 0, rind = array.size() - 1;
		while (1)
		{
			if (lind >= rind)return res;
			int temp = array[lind] + array[rind];
			if (temp == sum){
				res.push_back(array[lind]);
				res.push_back(array[rind]);
				return res;
			}
			else if (temp > sum)
				rind--;
			else
				lind++;
		}
	}
};

int main()
{
	cout << "end" << endl;
	system("pause");
}