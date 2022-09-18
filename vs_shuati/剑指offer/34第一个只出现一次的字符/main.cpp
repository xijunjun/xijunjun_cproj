#include <iostream>
using namespace std;


//字符有256种，可以用数组建立1个哈希表来记录每个字符首次出现的位置，当字符重复出现时哈希表中的值记为负数并不再更新，用来忽略有重复的字符，
//遍历完字符串过后，遍历哈希表找出最小的索引即可。
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