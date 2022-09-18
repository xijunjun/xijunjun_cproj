#include <iostream>
#include<algorithm>
using namespace std;

//����˼·���ݹ飬��*������ƥ�䣬����x*��0����������ƥ��Ĵ���
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		return ismatch(str, pattern, 0, 0);
	}
	bool ismatch(char* s, char* p, int si, int pi)
	{
		if (p[pi] == 0 && s[si] == 0)return true;//������ͬʱ����
		if (p[pi] == 0 && s[si] != 0)return false;//p���ף���s���뵽�ף���֮��δ�أ���Ϊp������*
		if (s[si] == 0 && p[pi] != 0 && p[pi + 1] != '*')return false;
		if (p[pi + 1] != '*')//��pi+1��Ϊ*����ôֱ���жϾͺ���
		{
			if (p[pi] != s[si] && p[pi] != '.')    return false;//����ǰ��s��p��ƥ�䣬�򷵻�false	
			else     return ismatch(s, p, si + 1, pi + 1);
		}
		while (1)//x*�ǿ���ƥ������εģ����Դ�0���ϱ���x*����ƥ��Ĵ���
		{
			if (s[si] == 0)    return ismatch(s, p, si, pi + 2);//s����ĩβ������
			if (p[pi] != s[si] && p[pi] != '.')    return ismatch(s, p, si, pi + 2);//��ʧ�䣬��p������λ�������ݹ�
			if (ismatch(s, p, si, pi + 2))    return true;//һ�������Ӵ�ƥ��ɹ��Ϳ��Է�����
			si++;
		}
	}
};


int main()
{

	Solution mys;
	cout << mys.match("aa",".*b*")<<endl;


	cout << "end" << endl;
	system("pause");
}