#include <iostream>
using namespace std;




//��һ����ϣ������¼
class Solution {
public:
	bool duplicate(int numbers[], int length, int* duplication) {
		bool *p = new bool[length]{};
		for (int i = 0; i<length; i++)
		{
			if (p[numbers[i]] == 0)
			{
				p[numbers[i]] = 1;
			}
			else {
				*duplication = numbers[i];
				return true;
			}

		}
		return false;
	}
};
int main()
{
	cout << "end" << endl;
	system("pause");
}