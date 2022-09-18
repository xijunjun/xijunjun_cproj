#include <iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty() || pushV.size() != popV.size())return false;
		int left = 0, index = 0;
		stack<int> stk;
		while (1)
		{
			if ((!stk.empty()) && stk.top() == popV[index]){
				index++;
				stk.pop();
			}
			else{
				bool nofind = 1;
				for (int i = left; i <= pushV.size() - 1; i++){
					if (popV[index] == pushV[i]){ index++; left = i + 1; nofind = 0; break; }
					stk.push(pushV[i]);
				}
				if (nofind)return false;
			}
			if (index == popV.size())return true;
		}
		return true;
	}
};
class Solution1 {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty() || pushV.size() != popV.size())return false;
		int left = 0, index=0;
		stack<int> stk;
		while (1)
		{
			if ((!stk.empty())&&stk.top() == popV[index]){
				index++;
				stk.pop();
			}
			else{
			bool nofind = 1;
			for (int i = left; i <= pushV.size() - 1; i++){
				if (popV[index] == pushV[i]){ index++; left = i + 1; nofind = 0; break; }
				stk.push(pushV[i]);
		    }
			if (nofind)return false;
		   }
		  if (index == popV.size())return true;
		}
		return true;
	}
};
int main()
{
	int  v1[] = { 1,2,3,4,5};
	int  v2[] = { 4, 3, 5,1,2};
	vector<int> vpush(&v1[0], &v1[sizeof(v1) / sizeof(int)]), vpop(&v2[0], &v2[sizeof(v2) / sizeof(int)]);


	Solution mys;
	cout << mys.IsPopOrder(vpush, vpop) << endl;
	cout << "end" << endl;
	system("pause");
}