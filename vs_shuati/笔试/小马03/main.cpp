#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;
void ank(vector<int>a, int ind)
{
	if (ind == a.size())
	{
		for (auto it : a)
			cout << it ;
		cout << endl;
		return;
	}
	for (int i = ind; i < a.size(); i++)
	{
		swap(a[ind], a[i]);
		ank(a, ind + 1);
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int>a;
	for (int i = 0; i < n; i++)
		a.push_back(i + 1);
	ank(a, 0);
	system("pause");
	return 0;
}