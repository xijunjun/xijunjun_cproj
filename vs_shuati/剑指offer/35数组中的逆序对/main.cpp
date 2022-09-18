#include <iostream>
#include<vector>
using namespace std;

//����Ļ���˼·�����Σ��ںϲ�������ʱ��һ�����ɣ��ɼ��ٱȽϴ������������͸��Ӷȡ�
//���ι���Ҫ˼�����ʵĺϲ����ԣ�Ҳ���Ǽ���������������ϲ�����������ԡ�
//������ʵ���ϲο��鲢����ֻ���ںϲ�������ʱ��ÿ�����ж��������������鹹�ɵ�����Ը���


//�������Һϲ�
class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.size() == 0)
			return 0;
		vector<int>temp(data);
		unsigned long long cnt = 0;//ע��cnt�����ͣ�������Ŀ��ȡֵ��Χ
		cnt_inverse(data, temp, 0, data.size() - 1, cnt);
		return cnt % 1000000007;
	}

	void  cnt_inverse(vector<int>&a, vector<int>&b, int st, int ed, unsigned long long &cnt)
	{
		if (ed <= st)return;
		int mid_index = (st + ed) / 2;
		cnt_inverse(a, b, st, mid_index, cnt);
		cnt_inverse(a, b, mid_index + 1, ed, cnt);
		for (int i = st; i <= ed; i++)
			b[i] = a[i];
		int  t2 = mid_index + 1, t1 = st;
		for (int i = st; i <= ed; i++)
		{
			if (t1 > mid_index)//�����鵽ͷ
				a[i] = b[t2++];
			else if (t2>ed)//�����鵽ͷ
				a[i] = b[t1++];
			else//������ȷ���ϲ�Ϊ�������飬��������ȡ��С�������ȽϹ����У�һ��������������С�������������������ԣ���������Ե�����Ϊ��������ʣ�µ�������������Ϊ
				//��Ϊ�����鶼Ϊ�������������鵱ǰ��С���������鵱ǰ�������������鵱ǰ��С����������ʣ�µ���������
				a[i] = b[t1] < b[t2] ? b[t1++] : (cnt += mid_index - t1 + 1, b[t2++]);//ע����е�����,��������������ȼ����
		}
	}

};

//��������ϲ�2
class Solution2 {
public:
	int InversePairs(vector<int> data) {
		if (data.size() == 0)
			return 0;
		vector<int>temp(data);
		unsigned long long cnt = 0;//ע��cnt�����ͣ�������Ŀ��ȡֵ��Χ
		cnt_inverse(data, temp, 0, data.size() - 1, cnt);
		return cnt % 1000000007;
	}

	void  cnt_inverse(vector<int>&a, vector<int>&b, int st, int ed, unsigned long long &cnt)
	{
		if (ed <= st)return;
		int mid_index = (st + ed) / 2;
		cnt_inverse(a, b, st, mid_index, cnt);
		cnt_inverse(a, b, mid_index + 1, ed, cnt);
		for (int i = st; i <= ed; i++)
			b[i] = a[i];
		int  t1 = mid_index, t2 = ed;
		for (int i = ed; i >= st; i--)
		{
			if (t1 <st)//�����鵽ͷ
				a[i] = b[t2--];
			else if (t2 <mid_index + 1)//�����鵽ͷ
				a[i] = b[t1--];
			else
				a[i] = b[t1] > b[t2] ? (cnt += t2 - (mid_index + 1) + 1, b[t1--]) : b[t2--];
		}
	}
};




//�鲢����
void  merge_sort(int *a, int *b, int st, int ed)
{
	if (ed <= st)return;
	int mid_index = (st + ed) / 2;
	merge_sort(a, b, st, mid_index);
	merge_sort(a, b, mid_index + 1, ed);
	for (int i = st; i <= ed; i++)
		b[i] = a[i];
	int  t2 = mid_index + 1, t1 = st;
	for (int i = st; i <= ed; i++)
	{
		if (t1 > mid_index)
			a[i] = b[t2++];
		else if (t2>ed)
			a[i] = b[t1++];
		else 
			a[i] = b[t1] < b[t2] ? b[t1++] : b[t2++];
	}
}


int main()
{
	int a[] = { 3,8,2,1,5,4};
	int b[6];
	memcpy(b, a, 6 * sizeof(int));
	Solution mys;
	vector<int>va(&a[0],&a[6]);
	cout<<mys.InversePairs(va);

	//merge_sort(a, b, 0, 3);

	//for (int i = 0; i < 4; i++)
	//{
	//	cout << a[i] << ",";
	//}
	//cout << endl;

	//int k;
	//k = (3<2) ? 1, 2 : 3,4;//��������������ȼ����ִ��˳��Ϊ   ((3<2) ? 1, 2 : 3),4
	//cout << "k: " << k<< endl;


	cout << "end" << endl;
	system("pause");
}