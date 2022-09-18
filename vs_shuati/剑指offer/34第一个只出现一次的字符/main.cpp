#include <iostream>
using namespace std;


//�ַ���256�֣����������齨��1����ϣ������¼ÿ���ַ��״γ��ֵ�λ�ã����ַ��ظ�����ʱ��ϣ���е�ֵ��Ϊ���������ٸ��£������������ظ����ַ���
//�������ַ������󣬱�����ϣ���ҳ���С���������ɡ�
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int index_table[256] = { 0 }, min_index = 0x0f000000;
		for (int i = 0; i < str.size();i++)
		{
			int chr = int(str[i]);
			if (index_table[chr] == 0){ index_table[chr] = i + 1; }
			else if (index_table[chr] > 0){ index_table[chr] = -1; }
		}
		for (int i = 0; i < 256;i++)
		{
			if (index_table[i]>0 && index_table[i] < min_index)
				min_index = index_table[i];
		}
		if (min_index == 0x0f000000)return -1;
		return min_index - 1;
	}
};
int main()
{
	Solution mys;
	cout << mys.FirstNotRepeatingChar("eabcdae") << endl;
	cout << "end" << endl;
	system("pause");
}