#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;

bool isPrime(int num)
{
	if (num == 2 || num == 3)
		return true;
	int N = sqrt(num);
	for (int k = 2; k <= N; k++)
	if (num%k == 0)return false;
	return true;
}
void func(int x, vector<int>a)
{
	map<int, int>res;
	if (isPrime(x))
		cout << "1 1" << endl << x << " 1";
	else
	{
		int count = 0;
		while (count<a.size())
		{
			if (x%a[count])
				count++;
			else
			{
				res[a[count]] += 1;
				x /= a[count];
			}
		}
		for (auto it : res)
			cout << it.first << " " << it.second << endl;
	}
}

int main()
{
	int x;
	cin >> x;
	if (x == 1){
		cout << "1 1";
		return 0;
	}
	vector<int>a;
	int count = 0;
	for (int i = 2; i <= x / 2; i++)
	if (isPrime(i))
		a.push_back(i);
	func(x, a);
	system("pause");
	return 0;
}
