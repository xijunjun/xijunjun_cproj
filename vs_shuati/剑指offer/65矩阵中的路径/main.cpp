#include <iostream>
using namespace std;


//程序实现的思路有点类似全排列
//遍历矩阵每个点作为起始点，然后通过一个函数判断能否找到一条以此点为起点的路径
//函数可以使用递归来写，若当前点匹配上了，那么将该点的访问状态记为已访问，然后判断向上下左右走一步形成的子问题，若子问题全都没匹配上，那么恢复该点为未访问状态，也就是回溯。
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		bool *visited = new bool[rows*cols]{};
		int sind = 0, mind = 0, length = rows*cols;
		for (int i = 0; i<length; i++)
		{
			if (rfunc(matrix, str, visited, rows, cols, sind, i))
				return true;
		}
		return false;
	}
	bool rfunc(char* matrix, char* str, bool *visited, int rows, int cols, int sind, int mind)
	{
		if (str[sind] == 0)return true;
		if (mind<0 || mind >= rows*cols || visited[mind] == 1 || matrix[mind] != str[sind])return false;
		visited[mind] = 1;
		if (rfunc(matrix, str, visited, rows, cols, sind + 1, mind + 1) ||
			rfunc(matrix, str, visited, rows, cols, sind + 1, mind - 1) ||
			rfunc(matrix, str, visited, rows, cols, sind + 1, mind + cols) ||
			rfunc(matrix, str, visited, rows, cols, sind + 1, mind - cols))
			return true;
		visited[mind] = 0;
		return false;
	}
};
int main()
{
	cout << "end" << endl;
	system("pause");
}