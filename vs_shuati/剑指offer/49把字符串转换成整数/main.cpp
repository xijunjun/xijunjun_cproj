#include <iostream>
using namespace std;


class Solution {
public:
	int StrToInt(string str) {
		int num = 0, wei = 1;
		if (str.empty())return num;
		if (str[0] == '+')//����ֻ�ܳ����ڵ�һλ�����ȴ������λ���������str���޳�
			str = str.substr(1, str.size() - 1);
		if (str[0] == '-')
		{
			wei = -1;
			str = str.substr(1, str.size() - 1);
		}
		for (int i = str.size() - 1; i >= 0; i--)
		{
			if (i != str.size() - 1)wei *= 10;
			if (str[i]>'9' || str[i]<'0')
				return 0;
			else
				num += wei*int(str[i] - '0');
		}
		return num;
	}
};

int main()
{
	cout << "end" << endl;
	system("pause");
}