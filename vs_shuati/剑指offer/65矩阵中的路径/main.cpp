#include <iostream>
using namespace std;


//����ʵ�ֵ�˼·�е�����ȫ����
//��������ÿ������Ϊ��ʼ�㣬Ȼ��ͨ��һ�������ж��ܷ��ҵ�һ���Դ˵�Ϊ����·��
//��������ʹ�õݹ���д������ǰ��ƥ�����ˣ���ô���õ�ķ���״̬��Ϊ�ѷ��ʣ�Ȼ���ж�������������һ���γɵ������⣬��������ȫ��ûƥ���ϣ���ô�ָ��õ�Ϊδ����״̬��Ҳ���ǻ��ݡ�
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