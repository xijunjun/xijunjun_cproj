#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
using namespace std;



int main()
{
	int x, y;
	cin >> x >> y;
	int t = x + y;
	int sum = t, i = 0;
	i = (sqrt(1 + 8 * sum) - 1) / 2;

	while (1)
	{
		i++;
			sum += i;
		if (sum>t)return 0;
		if (sum == t)break;
	}
	int tmp = i;
	sum = 0;
	while (1)
	{
		sum += i;
		if (sum >= 7)
		{
			cout << tmp - i + 1;
			break;
		}
		i--;
	}

	system("pause");
	return 0;
}