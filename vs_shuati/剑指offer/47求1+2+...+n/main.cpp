#include <iostream>
using namespace std;


//�߼������·����
class Solution1 {
public:
	int Sum_Solution(int n) {
		int ans = n;
		ans && (ans += Sum_Solution(n - 1));
		return ans;
	}
};
//����ָ��
int Sum_Solution2(int n);
int rt0(int n);
int(*(p[2]))(int n) = { rt0, Sum_Solution2 };
int rt0(int n)
{
	return 0;
}
int Sum_Solution2(int n) {
	return n + (p[n != 0])(n - 1);//return n+(*p[n!=0])(n-1);Ҳ���ԣ�����ָ���ֱ�ӵ�1�����ã�Ҳ���Լ�*��
}
class Solution {
public:
	int Sum_Solution(int n) {
		return Sum_Solution2(n);
	}
};

int fun(int n)
{
	return n;
}

int main()
{
	int(*p)(int n) = fun;

	cout << (*p)(2) << endl;
	cout << "end" << endl;
	system("pause");
}