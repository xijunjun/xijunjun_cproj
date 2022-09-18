#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;

bool  is_sit_2(vector<int>&a)
{
	int last=-1,d=-100000000;
	for (int i = 1; i < a.size();i+=2)
	{
		if (a[i] % 2 == 0)return false;
		if (last == -1){
			last = a[i];
		}
		else {
			if (d == -100000000)
				d = a[i] - last;
			if (d==0||d != a[i] - last)
				return false;
		}
		last = a[i];
	}
	return true;
}

bool  is_sit_3(vector<int>&a)
{
	int last = -1, d = -100000000;
	for (int i = 0; i < a.size(); i ++)
	{
		if (a[i] % 2 == 0)return false;
		if (last == -1){
			last = a[i];
		}
		else {
			if (d == -100000000)
				d = a[i] - last;
			if (d == 0 || d != a[i] - last)
				return false;
		}
		last = a[i];
	}
	return true;
}

bool  is_sit_4(vector<int>&a)
{
	int last = -1, d = -100000000;
	for (int i = 0; i < a.size(); i += 2)
	{
		if (a[i] % 2 == 0)return false;
		if (last == -1){
			last = a[i];
		}
		else {
			if (d == -100000000)
				d = a[i] - last;
			if (d == 0 || d != a[i] - last)
				return false;
		}
		last = a[i];
	}
	return true;
}
int main(){
	#define CIN myin
	ifstream myin("input.txt");
	int  n;
	CIN >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
		CIN >> a[i];

	if (a.size()==2)
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << endl;
		return 0;
	}


	if (is_sit_2(a))
	{
		int d = (a[3] - a[1]) / 2;
		a[0] = a[1] - d;
		if (a[0] % 2 == 1)a[0] *= 2;
		for (int i = 0; i < n; i++)
			cout << a[0] + d*i << endl;
	}
	if (is_sit_3(a))
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << endl;
	}
	if (is_sit_4(a))
	{
		int d = (a[2] - a[0]) / 2;
		for (int i = 0; i < n; i++)
			cout << a[0] + d*i << endl;
	}



	system("pause");
	return 0;
}