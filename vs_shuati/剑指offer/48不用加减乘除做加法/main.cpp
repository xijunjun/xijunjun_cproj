#include <iostream>
using namespace std;
#include<vector>
//���ӷ��ֽ�Ϊ  ���������+��λ������������ǰ�����㣬��������������һλ�ǽ�λ����
//ע�������jinwei(num2��Ϊʲô���ջ��Ϊ0����������ÿ�εݹ鶼��(num1&num2) << 1;Ҳ����˵��ʹnum2����ᱻ0��������������
class Solution1 {
public:
	int Add(int num1, int num2)
	{
		int half_sum = num1^num2;
		int jinwei = (num1&num2) << 1;
		if (jinwei == 0)
			return half_sum;
		else return Add(half_sum, jinwei);
	}
};
//�ֽ�num1ת��Ϊָ��a������a[num2]�ĵ�ַ
class Solution {
public:
	int Add(int num1, int num2)
	{
		char* a = reinterpret_cast<char*>(num1);
		return reinterpret_cast<long>(&(a[num2]));
	}
};

int main()
{
	//vector<int> dict(256,-1);
	cout << "end" << endl;
	system("pause");
}