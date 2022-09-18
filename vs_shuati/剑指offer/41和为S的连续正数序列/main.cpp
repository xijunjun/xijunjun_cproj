#include <iostream>
#include<vector>
#include<math>
using namespace std;


//����ʼ��Ϊa,����Ϊk,��Ϊx�����ݵȲ����к͹�ʽ���ɵ�a=(2*x-k*k+k)/2*k��a����������x��֪������ֻ�����k����(2*x-k*k+k)/2*k��������ʱ��ɼ�Ϊ�ϸ�����
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > res;
		int dsum = sum << 1;
		int maxk = int(sqrtf(dsum));
		for (int i = maxk; i >= 2; i--)
		{
			if (((dsum - i*i + i) % (i << 1)) == 0 && (dsum - i*i + i)>0)
			{
				vector<int> comb;
				int base = (dsum - i*i + i) / (i << 1);
				for (int j = 0; j < i; j++)
				{
					comb.push_back(base + j);
				}
				res.push_back(comb);
			}
		}
		return res;
	}
};

int main()
{
	cout << "end" << endl;
	system("pause");
}