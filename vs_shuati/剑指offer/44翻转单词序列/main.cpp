#include <iostream>
#include<vector>
#include <string>
using namespace std;

//һ�����ӷ�Ϊ���ʣ������ǿո��ַ����ͼ���������ո��ַ������֣�����ֻ��Ӻ���ǰ�����������ʵ��ַ���֮ǰ���ַ����ԣ��ո�ͷǿո񣩲�ͬ���������䣬
//��ʱ������1���ҵ����ʻ�������߽磬ͬʱ��¼���
class Solution {
public:
	string ReverseSentence(string str) {
		string res;
		int lenth = str.size();
		bool is_space = str[lenth-1]==' ';
		int wid = 0;
		for (int i = lenth - 1; i >= 0;i--)
		{
			if (is_space ^ (str[i] == ' '))
				wid++;
			else//�������������
			{
				res += string(str.substr(i+1,wid));
				is_space = 1-is_space;
				wid = 1;
			}
		}
		res += string(str.substr(0, wid));
		return res;
	}
};

int main()
{
	Solution mys;

	string a = "i am a boy  ";

	cout << mys.ReverseSentence(a) << endl;

	cout << "end" << endl;
	system("pause");
}