#include <iostream>
#include<vector>
#include<queue>
using namespace std;

//�ؼ��ʣ�˫����У��ö��б����ϵı��µĴ�
//��Щ��Ӧ�ñ��Ƴ����У�
//1.����ѹ�����С��������Ϊ��ѹ������ڽ������Ļ����У��϶����뵱ǰ�����е�������һ��ͬ�������ڱ���С����������Щͬ���Ĵ����У�������Ҳ�Ϳ϶��������Ǳ���С����
//2.���ڴ����ڵ��������ڴ��ڶ����Ƴ�������һ���Ƕ��ף���Ϊ���ڴ��ڵ��������ֻ��1�����������ڶ��������Ƚ��ӵģ�������ϡ��ġ���������С�ġ�
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		deque<int>dq;
		vector<int> res;
		if (size <= 0||size>num.size())return res;
		for (int i = 0; i<num.size(); i++)
		{
			int min_ind = i - size + 1;//����i�������������߽�
			while (!dq.empty())//��ѹ���µ�i֮ǰ������β��С�ڵ���num[i]�Ķ������ȥ
			{
				if (num[dq.back()] <= num[i])
					dq.pop_back();
				else break;
			}
			dq.push_back(i);
			if (min_ind >= 0 && dq.front()<min_ind)//����ͷ������С�ڴ�����߽磬���Ƴ���ͷ
				dq.pop_front();
			if (min_ind >= 0)
				res.push_back(num[dq.front()]);//����߽���ڵ���0ʱ��ʼ��¼��ͷ
		}
		return res;
	}
};
int main()
{
	int a[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector<int>va(&a[0],&a[8]);
	Solution mys;
	vector <int>res = mys.maxInWindows(va,8);
	for (int i = 0; i < res.size();i++)
	{
		cout << res[i] << endl;
	}

	cout << "end" << endl;
	system("pause");
}