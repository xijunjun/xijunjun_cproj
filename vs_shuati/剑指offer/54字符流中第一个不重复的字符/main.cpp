#include <iostream>
using namespace std;
//µÍĞ§×ö·¨
class Solution
{
public:
	//Insert one char from stringstream
	string mstr = "";
	int hash[256] = { 0 };
	char rtval = '#';
	int lenth = 0;
	void Insert(char ch)
	{
		lenth++;
		rtval = '#';
		mstr.push_back(ch);
		if (++hash[ch]>2)hash[ch] = 2;
		for (int i = 0; i<lenth; i++)
		{
			if (hash[mstr[i]] == 1)
			{
				rtval = mstr[i];
				break;
			}
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		return rtval;
	}

};
class Solution
{
public:
	//Insert one char from stringstream
	int table[256] = { 0 };
	string m_str = "";
	int index = -1, indend = -1;
	char rtval = '#';
	void Insert(char ch)
	{
		if (++table[ch]>2)table[ch] = 2;
		indend++;
		m_str.push_back(ch);
		if (rtval == ch || rtval == '#')
		{
			while (1)
			{
				index++;
				if (index > indend)
				{
					rtval = '#';
					index--;
					break;
				}
				if (table[m_str[index]] == 1)
				{
					rtval = m_str[index];
					break;
				}
			}
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		return rtval;
	}

};
int main()
{
	cout << "end" << endl;
	system("pause");
}