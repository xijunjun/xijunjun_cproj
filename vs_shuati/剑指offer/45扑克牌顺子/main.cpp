#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


//������Ȼ��������飬�ȼ�¼Ϊ0�ĸ�����Ȼ���жϵ�ǰ����ǰһ����֮��Ĳ����0�򷵻�flase������1��˵����ǰ����ǰһ��������������������������1���ô�С�������
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() == 0)return false;
		sort(numbers.begin(), numbers.end());
		int numzero = 0;
		for (int i = 0; i<numbers.size(); i++)
		{
			if (numbers[i] == 0)
				numzero++;
			else if (i>0 && numbers[i - 1] != 0){
				int dif = numbers[i] - numbers[i - 1];
				if (dif == 0)
					return false;
				else if (dif>1)
					numzero -= dif - 1;
				if (numzero<0)
					return false;
			}
		}
		return true;
	}
};
int main()
{
	cout << "end" << endl;
	system("pause");
}


