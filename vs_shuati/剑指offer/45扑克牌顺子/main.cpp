#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


//先排序，然后遍历数组，先记录为0的个数，然后判断当前数与前一个数之间的差，等于0则返回flase，等于1则说明当前数与前一个数连续，继续遍历，若大于1则用大小王来填充
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() == 0)return false;
		sort(numbers.begin(), numbers.end());
		int numzero = 0;
		for (int i = 0; i<numbers.size(); i++)
		{
			if (numbers[i] == 0)
				numzero++;
			else if (i>0 && numbers[i - 1] != 0){
				int dif = numbers[i] - numbers[i - 1];
				if (dif == 0)
					return false;
				else if (dif>1)
					numzero -= dif - 1;
				if (numzero<0)
					return false;
			}
		}
		return true;
	}
};
int main()
{
	cout << "end" << endl;
	system("pause");
}


