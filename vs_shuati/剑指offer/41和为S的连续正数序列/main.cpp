#include <iostream>
#include<vector>
#include<math>
using namespace std;


//记起始数为a,个数为k,和为x，根据等差数列和公式，可得a=(2*x-k*k+k)/2*k，a是正整数，x已知，所以只需遍历k，若(2*x-k*k+k)/2*k是正整数时便可记为合格的组合
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > res;
		int dsum = sum << 1;
		int maxk = int(sqrtf(dsum));
		for (int i = maxk; i >= 2; i--)
		{
			if (((dsum - i*i + i) % (i << 1)) == 0 && (dsum - i*i + i)>0)
			{
				vector<int> comb;
				int base = (dsum - i*i + i) / (i << 1);
				for (int j = 0; j < i; j++)
				{
					comb.push_back(base + j);
				}
				res.push_back(comb);
			}
		}
		return res;
	}
};

int main()
{
	cout << "end" << endl;
	system("pause");
}