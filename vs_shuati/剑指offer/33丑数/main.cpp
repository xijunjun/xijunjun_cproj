#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//下一个丑数一定是前面某个丑数乘以2、3、5中的一个因子得到的，丑数数量是不断增长的，假设首先用最小的丑数f(2)=f(1)*2构造了下一个丑数，那么f(1)不能再通过*2来
//构造丑数了，而下一个用*2构造的丑数只能是f(2)，因为f(2)是目前能用*2构造丑数中最小的一个。对于*3和*5构造是一样的道理。
//下一个丑数一定是前面某个丑数乘以2、3或5构造得到的。
//f(1)=1;	f(2)=min{f(1)*2,f(1)*3,f(1)*5}=2;	f(3)=min{f(2)*2,f(1)*3,f(1)*5}=3	f(4)=min{f(2)*2,f(2)*3,f(1)*5}=4
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index < 7)return index;
		vector<int> res(index);
		int ind2 = 0, ind3 = 0, ind5 = 0;
		res[0] = 1;
		for (int i = 1; i < index;i++)
		{
			res[i] = min(min(res[ind2] * 2, res[ind3] * 3), res[ind5] * 5);
			if (res[i] == res[ind2] * 2)ind2++;//!!!注意此处不能跟else，因为有可能res[ind2] * 2,res[ind3],3=res[ind5] * 5有可能相等！
			if (res[i] == res[ind3] * 3)ind3++;
			if (res[i] == res[ind5] * 5)ind5++;
		}
		return res[index - 1];
	}
};

int main()
{
	Solution mys;
	cout << mys.GetUglyNumber_Solution(7) << endl;
	cout << "end" << endl;
	system("pause");
}