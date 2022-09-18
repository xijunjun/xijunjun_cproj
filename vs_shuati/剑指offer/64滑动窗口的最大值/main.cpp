#include <iostream>
#include<vector>
#include<queue>
using namespace std;

//关键词：双向队列，让队列保持老的比新的大
//哪些数应该被移出队列？
//1.比新压入的数小的数；因为新压入的数在接下来的滑窗中，肯定会与当前队列中的数至少一次同窗，对于比它小的数，在这些同窗的窗口中，最大的数也就肯定不可能是比它小的数
//2.不在窗口内的数；不在窗口而被移出的数据一定是队首，因为不在窗口的数据最多只有1个，而队首在队列中最先进队的，它是最“老”的、索引是最小的。
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		deque<int>dq;
		vector<int> res;
		if (size <= 0||size>num.size())return res;
		for (int i = 0; i<num.size(); i++)
		{
			int min_ind = i - size + 1;//根据i计算出滑窗的左边界
			while (!dq.empty())//在压入新的i之前，将队尾中小于等于num[i]的都清除出去
			{
				if (num[dq.back()] <= num[i])
					dq.pop_back();
				else break;
			}
			dq.push_back(i);
			if (min_ind >= 0 && dq.front()<min_ind)//若队头的索引小于窗口左边界，则移除队头
				dq.pop_front();
			if (min_ind >= 0)
				res.push_back(num[dq.front()]);//当左边界大于等于0时开始记录队头
		}
		return res;
	}
};
int main()
{
	int a[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector<int>va(&a[0],&a[8]);
	Solution mys;
	vector <int>res = mys.maxInWindows(va,8);
	for (int i = 0; i < res.size();i++)
	{
		cout << res[i] << endl;
	}

	cout << "end" << endl;
	system("pause");
}