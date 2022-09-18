#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> va;
	int tlx = 0, tly = 0, brx = matrix[0].size()-1, bry = matrix.size() - 1;
	while (1)
	{	
		for (int i = tlx; i <= brx; i++)//左到右
		{
			va.push_back(matrix[tly][i]);
		}
		tly++; if (tly > bry)break;
		for (int i = tly; i <= bry; i++)//上到下
		{
			va.push_back(matrix[i][brx]);
		}
		brx--; if (tlx>brx)break;
		for (int i = brx; i >=tlx; i--)//右到左
		{
			va.push_back(matrix[bry][i]);
		}
		bry--; if (tly > bry)break;
		for (int i = bry; i >= tly; i--)//下到上
		{
			va.push_back(matrix[i][tlx]);
		}
		tlx++; if (tlx>brx)break;
	}
	return va;
  }
};
int main()
{
	vector<vector<int> > matrix;
	for (int j = 0; j < 4; j++)
	{
		vector<int> va;
		for (int i = 0; i < 4; i++)
		{	
			va.push_back(j*4+i+1);
		}
		matrix.push_back(va);
	}
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			cout << matrix[j][i] << " ";
		}
	}
	cout << endl;
	Solution mys;
	vector<int> clock_vec = mys.printMatrix(matrix);
	for (int i = 0; i < clock_vec.size(); i++)
	{
		cout << clock_vec[i] << " ";
	}
	cout << "end" << endl;
	system("pause");
}