#include <iostream>
#include<vector>
#include<algorithm>
#include<assert.h>
using namespace std;

char* mystrcpy(char *dst,const char *src)
{
	assert(dst&&src);
	char *tmp = dst;
	while ((*tmp++ = *src++) != 0);
	return dst;
}
int mystrcmp(const char* a,const char*b)
{
	assert(a&&b);
	while (1)
	{
		if (*a == 0 && *b == 0)return 0;
		if (*a == 0||*a<*b)return -1;
		if (*b == 0 || *a>*b)return 1;
		a++;
		b++;
	}
}
char *mystrcat(char* dst, const char*src)
{
	char *res=dst;
	assert(dst&&src);
	while (*dst!= 0)dst++;
	while ((*dst++ = *src++) != 0);
	return res;
}


int main()
{
	char a[100] = {0};
	string s = "12344",s2="12345";
	//cout << mystrcpy(a,s.c_str());
	//cout<<mystrcmp(s.c_str(), s2.c_str())<<endl;
	//cout << strcmp(s.c_str(), s2.c_str()) << endl;

	mystrcat(a, s.c_str());
	mystrcat(a, s2.c_str());
	cout << a;

	cout  << endl;
	system("pause");
}