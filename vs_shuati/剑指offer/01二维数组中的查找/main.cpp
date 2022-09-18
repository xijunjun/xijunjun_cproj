#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include <fstream>
#include<sstream>
using namespace std;

class Solution2 {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())return 0;
		if (array[0].empty())return 0;//两重判断！！
		int w = array[0].size(), h = array.size();
		cout << w << "," << h << endl;
		int xstart = w - 1, ystart = 0;
		while (1)
		{
			int x_index = -1, y_index = -1;
			for (int i = xstart; i >= 0; i--)
			{
				if (array[ystart][i] == target)
					return 1;
				if (array[ystart][i] < target)
				{
					x_index = i;
					break;
				}
			}
			if (x_index == -1)return 0;
			xstart = x_index;

			for (int i = ystart; i <h; i++)
			{
				if (array[i][xstart] == target)
					return 1;
				if (array[i][xstart] > target)
				{
					y_index = i;
					break;
				}
			}
			if (y_index == -1)return 0;
			ystart = y_index;

		}
		//cout << "x_index:" << x_index << "  y_index:" << y_index << endl;
		return 1;
	}
};
class Solution3 {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())return 0;
		if (array[0].empty())return 0;//两重判断！！
		int w = array[0].size(), h = array.size();
		if (array[0][0] > target || array[h - 1][w - 1]<target)return 0;
		int xstart = w - 1, ystart = 0;
		while (1)
		{
			if (array[ystart][xstart] == target){ return 1; }
			if (array[ystart][xstart] > target)xstart--;
			else ystart++;
			if (xstart < 0 || ystart > h - 1)return 0;
		}
	}
};
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())return 0;
		if (array[0].empty())return 0;//两重判断！！
		int w = array[0].size(), h = array.size();
		int xstart = w - 1, ystart = 0;
		while (xstart >= 0 && ystart<h)
		{
			if (array[ystart][xstart] == target){ return 1; }
			if (array[ystart][xstart] > target)xstart--;
			else ystart++;
		}
		return 0;
	}
};
int main()
{

	vector<vector<int> > array;
	//vector<int> one_row;
	//array.push_back(one_row);
	for (int i = 0; i < 25; i++)
	{
		vector<int> one_row;
		for (int j = 0; j < 20; j++)
		{
			one_row.push_back(j+i*2);
		}
		array.push_back(one_row);
	}
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << array[i][j]<<",";
		}
		cout << endl;
	}

	Solution3 mys;
	cout << mys.Find(62, array) << endl;

	cout << "end" << endl;
	system("pause");
}