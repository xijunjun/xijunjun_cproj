/* strtok example */
#include <stdio.h>
#include <string.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	char str[] = "- This, a sample string.";
	char str2[] = "-   hello world";
	char * pch;
	printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(str, " ,.-");
	pch = strtok(str2, " ,.-");
	pch = strtok(NULL, " ,.-");
	//while (pch != NULL)
	//{
	//	printf("%s\n", pch);
	//	pch = strtok(NULL, " ,.-");
	//}
	cout << pch;
	system("pause");
	return 0;
}

