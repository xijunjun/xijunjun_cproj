#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;

int main()
{
	#define CIN myin
	ifstream myin("input.txt");
	int n;
	CIN >> n;
	vector<int>a;
	for (int i = 0; i < n; i++)
	{
		string s;
		CIN >> s;
		a.push_back(stoi(s.substr(s.size()-6)));
		//cout << *a.rbegin()<<endl;
	}
	sort(a.begin(),a.end());
	for (auto it : a)
		cout << it << endl;
	system("pause");
	return 0;
}