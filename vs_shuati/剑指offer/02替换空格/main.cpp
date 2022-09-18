#include <iostream>
#include <string.h>
#include<cstring>
#include<assert.h>
using namespace std;
class Solution2 {
public:
	void replaceSpace(char *(&str), int length) {
		assert(str!=NULL);
		length = 0;
		char *str2 = str;
		while (*str2 != '\0')
		{
			if (*str2==' ')length++;
			str2++;
		}
		
		str2 = str;
		char* r_str = new char[strlen(str)+length*2+1];
		char* new_str = r_str;
		while (*str2 != '\0')
		{
			if (*str2 == ' ')
			{
				*new_str++ = '%'; *new_str++ = '2'; *new_str++ = '0';
			}
			else
			{
				*new_str++ = *str2;
			}
			str2++;
		}	
		*new_str = '\0';
		str2 = NULL;
		new_str = NULL;
		str = r_str;
		cout << str << endl;
	}
};
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL)return;
		int kg_num = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
				kg_num++;
		}
		int tail_index = length + kg_num * 2 - 1;
		for (int i = length - 1; i >= 0; i--)
		{
			if (str[i] == ' ')
			{
				str[tail_index--] = '0';
				str[tail_index--] = '2';
				str[tail_index--] = '%';
			}
			else
			{
				str[tail_index--] = str[i];
			}
		}

	}
};
int main()
{
	char *str2 = "We are happy.";
	//cout << "str2[0]:" << str2[0] << endl;
	//str2[0] = '0';

	char str[] = "We are happy.      ";
	Solution2 mys;
	mys.replaceSpace(str2, 13);
	printf("%s",str2);

	cout<<endl << "hello";
	system("pause");

}