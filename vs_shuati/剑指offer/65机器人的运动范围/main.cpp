#include <iostream>
#include <string>
using namespace std;
//把大于k的格子视为墙壁，直接从(0,0)的位置开始从四个方向访问数组，记录访问过的点和不符合条件的点，下次遇到就直接跳过了。
class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (cols == 0)return 0;
		bool* visited = new bool[rows*cols]{};
		int cnt = 0;
		rfunc(visited, threshold, rows, cols, 0, 0, cnt);
		return cnt;
	}
	void rfunc(bool *visited, int threshold, int rows, int cols, int x, int y, int &cnt)
	{
		if (visited[y*cols + x] == 1 || x >= cols || x<0 || y >= rows || y<0)
			return;
		visited[y*cols + x] = 1;
		if (!isvalid(x, y, threshold))
			return;
		cnt++;
		rfunc(visited, threshold, rows, cols, x - 1, y, cnt);
		rfunc(visited, threshold, rows, cols, x + 1, y, cnt);
		rfunc(visited, threshold, rows, cols, x, y - 1, cnt);
		rfunc(visited, threshold, rows, cols, x, y + 1, cnt);
	}
	bool isvalid(int x, int y, int k)
	{
		string s = to_string(x) + to_string(y);
		int sum = 0;
		for (int i = 0; i<s.size(); i++){
			sum += s[i] - '0';
		}
		return sum <= k;
	}
};
int main()
{
	cout << "end" << endl;
	system("pause");
}