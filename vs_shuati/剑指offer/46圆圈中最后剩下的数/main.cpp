#include <iostream>
#include<vector>
using namespace std;



//剑指offer解析
//核心思路：递归+解决子问题到原问题的索引映射
//(m-1)%n是n个人时选择的索引，所以下一次选择的索引就是m%n，在f(n-1,m)中被记为了0；所以f(n-1,m)+m%n将索引映射回f(n,m)但注意f(n-1,m)+m%n会使某些索引超过n-1,所以再对整体求余。
//将f(n-1,m)重排过后的索引映射回f(n,m)，f(n,m)=(f(n-1,m)+m%n)%n，f(1)=0;
class Solution1 {
public:
	int LastRemaining_Solution(unsigned int n, unsigned int m)
	{
		if (n <= 0)
			return n-1;
		else
			return (LastRemaining_Solution(n - 1, m) + m) % n;
	}
};
//循环实现
class Solution2 {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0) return -1;
		int s = 0;
		for (int i = 2; i <= n; i++){
			s = (s + m) % i;
		}
		return s;
	}
};

//数组记录状态，模拟整个过程
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n<1)return -1;
		bool *p = new bool[n]{};
		int index = 0;//数组p用来记录n个小朋友的状态，index用来记录下次报数的起始位置
		for (int i = n - 1; i >= 1; i--)
		{
			int s = (m - 1) % (i + 1);//从当前位置应该继续走多少步，注意必须确保index移动到的是下一个0的位置，1代表小朋友已经出局
			while (1)
			{
				if (p[index] == 0 && --s<0)break;
				index = ++index >= n ? index%n : index;
			}
			p[index] = 1;
		}
		index = 0;
		while (p[index++] == 1);//找出状态为0的小朋友的索引
		delete p;
		return index - 1;
	}
};
class Solution2 {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n <= 1)return n - 1;
		vector<bool>v(n, 0);
		int ind = 0;
		for (int i = n; i >= 2; i--)
		{
			int cnt = (m - 1) % i;
			while (1)
			{
				if (v[ind] == 0)cnt--;
				if (cnt<0)break;
				if (++ind >= n)ind %= n;
			}
			v[ind] = 1;
		}
		int k = 0;
		for (; k <= n - 1; k++)
		if (!v[k])break;
		return k;
	}
};

int main()
{
	Solution mys;
	cout << endl<<mys.LastRemaining_Solution(5,3) << endl;;

	cout << endl << (-3) % 5 << endl;


	cout << "end" << endl;
	system("pause");
}