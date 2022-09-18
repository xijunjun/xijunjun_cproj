#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��һ������һ����ǰ��ĳ����������2��3��5�е�һ�����ӵõ��ģ����������ǲ��������ģ�������������С�ĳ���f(2)=f(1)*2��������һ����������ôf(1)������ͨ��*2��
//��������ˣ�����һ����*2����ĳ���ֻ����f(2)����Ϊf(2)��Ŀǰ����*2�����������С��һ��������*3��*5������һ���ĵ���
//��һ������һ����ǰ��ĳ����������2��3��5����õ��ġ�
//f(1)=1;	f(2)=min{f(1)*2,f(1)*3,f(1)*5}=2;	f(3)=min{f(2)*2,f(1)*3,f(1)*5}=3	f(4)=min{f(2)*2,f(2)*3,f(1)*5}=4
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index < 7)return index;
		vector<int> res(index);
		int ind2 = 0, ind3 = 0, ind5 = 0;
		res[0] = 1;
		for (int i = 1; i < index;i++)
		{
			res[i] = min(min(res[ind2] * 2, res[ind3] * 3), res[ind5] * 5);
			if (res[i] == res[ind2] * 2)ind2++;//!!!ע��˴����ܸ�else����Ϊ�п���res[ind2] * 2,res[ind3],3=res[ind5] * 5�п�����ȣ�
			if (res[i] == res[ind3] * 3)ind3++;
			if (res[i] == res[ind5] * 5)ind5++;
		}
		return res[index - 1];
	}
};

int main()
{
	Solution mys;
	cout << mys.GetUglyNumber_Solution(7) << endl;
	cout << "end" << endl;
	system("pause");
}