#include <iostream>
#include<vector>
using namespace std;

//��Ŀ��һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
//���ݹ�ʽ�����������A^B^B^C = A^0^C = A^C������ֱ�ӽ���������Ԫ�����ɵõ�A^C��ֵ������Ҫ�õ�A��ֵ����Ҫ���������й��˵�C��ֵ��
//A^C��ֵ���Է�ӳA��C�Ĳ�𣬹��˷�����A^C��ֵ��ѡ��bitΪ1��λ��Ϊɸѡ������ΪA��C����1λ��ֵһ����ͬ��
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int tp1 = 0;
		for (auto it = data.begin(); it != data.end(); it++)
			tp1 ^= *it;
		int one_bit = 1;
		while (one_bit){
			if ((one_bit&tp1) > 0)break;//ע����������ȼ�(one_bit&tp1) > 0��one_bit&tp1 > 0�ǲ�ͬ��
			one_bit = one_bit << 1;
		}
		*num1 = 0;
		*num2 = 0;
		for (auto it = data.begin(); it != data.end(); it++)
		{
			if (((*it)&one_bit) > 0)
				(*num1) ^= *it;
			else
				(*num2) ^= *it;
		}

	}
};

int main()
{


	cout << "end" << endl;
	system("pause");
}