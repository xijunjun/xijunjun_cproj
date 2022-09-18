#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	#define CIN myin
	ifstream myin("input.txt");
	int n;
	CIN >> n;
	vector<int>a(n);
	for (int i = 0; i < n;i++)
		CIN >> a[i];
	int len = a.size();
	for (int i = 0; i < n; i++)
		a.push_back(a[i]);
	int maxsum = 0;
	for (int i = 0; i < len; i++)
	{
		int sum = 0;
		for (int j = 0; j < len;)
		{
			sum += a[i + j];
			if (a[i + j] % 2 == 0)j+=2;
			else j += 3;
		}
		if (sum>maxsum)maxsum = sum;
	}
	cout << maxsum;
	system("pause");
	return 0;
}