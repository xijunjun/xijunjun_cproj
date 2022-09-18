#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
public:
	int lengthOfLongestSubstring(string s) {
		int table[256] = { 0 };//������¼�ϴγ��ֵ�λ��
		int length = 0;
		int cnt = 0, ignored_ind = 0;
		for (int i = 0; i<s.size(); i++)
		{
			if (table[s[i]] == 0 || table[s[i]]<ignored_ind){
				cnt++;
				table[s[i]] = 1 + i;
			}
			else {
				if (length<cnt)
					length = cnt;
				ignored_ind = table[s[i]];
				cnt = i - (table[s[i]] - 1);
				table[s[i]] = 1 + i;
			}
		}
		if (length<cnt)
			length = cnt;
		return length;
	}
};
//�ؼ��ʣ���ֵΪ�����Ĺ�ϣ��������߽�
//������������һ�������ڶ������Ϳ����ϸ�x��ߵĲ����Ա��ִ����ڵ��ַ��ǲ��ظ��ġ�
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		//���������������������⣬��Ҫ���⣺����жϷ����ظ����ظ�ʱ��δ���
		//�漰�ظ�������һ��ʹ�ù�ϣ�������
		//ʹ��һ����ϣ������¼�ַ�x�ϴγ��ֵ�λ�ã�����ַ�x�ϴγ��ֵ�����С����߽磬��ô˵�����µ���߽�������û�г��ֹ�
		//һ�������ظ�����Ҫ������߽�,��߽�Ӧ����Ϊ�ظ��ַ��ϴγ��ֵ�λ�ã�����ֻҪ��ϣ���е�ֵС����߽��Ǿ�û���ظ�
		vector<int>hash(256, -1);
		int left_bd = -1, maxl = 0;
		for (int i = 0; i<s.size(); i++)
		{
			if (hash[s[i]]>left_bd)
				left_bd = hash[s[i]];
			hash[s[i]] = i;
			maxl = max(maxl, i - left_bd);
		}
		return maxl;
	}
};

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		
	}
};
int main()
{

	vector<int>hash(256,-1);
	for (int i = 0; i <hash.size(); i++)
	{
		cout << hash[i] << ",";
	}
	cout << "end" << endl;
	system("pause");
}