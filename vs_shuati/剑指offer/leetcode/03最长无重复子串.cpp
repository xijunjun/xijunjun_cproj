#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
public:
	int lengthOfLongestSubstring(string s) {
		int table[256] = { 0 };//用来记录上次出现的位置
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
//关键词：用值为索引的哈希来更新左边界
//窗口慢慢增大，一旦遇到第二个，就砍掉上个x左边的部分以保持窗口内的字符是不重复的。
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		//类似连续子数组最大和问题，主要问题：如何判断发生重复？重复时如何处理？
		//涉及重复的问题一般使用哈希表来解决
		//使用一个哈希表来记录字符x上次出现的位置，如果字符x上次出现的索引小于左边界，那么说明在新的左边界起它还没有出现过
		//一旦发生重复就需要更新左边界,左边界应更新为重复字符上次出现的位置，所以只要哈希表中的值小于左边界那就没有重复
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