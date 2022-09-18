#include <iostream>
#include<vector>
using namespace std;
//�ݹ�汾
class Solution2 {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() == 0)return 0;
		int lindex = find_lindex(k, data, 0, data.size() - 1);
		if (lindex == -1)return 0;
		int rindex = find_rindex(k, data, 0, data.size() - 1);
		return rindex - lindex + 1;
	}
	int find_lindex(int num, vector<int> &data, int st, int ed)
	{
		if ((ed == st) && (data[st] != num))return -1;
		int mid = (st + ed) / 2;
		if (data[mid] == num)
		{
			if (mid - 1 >= st&&data[mid - 1] == num)
				return find_lindex(num, data, st, mid - 1);
			return mid;
		}
		if (data[mid] > num)
			return find_lindex(num, data, st, mid - 1);
		else
			return find_lindex(num, data, mid + 1, ed);
	}
	int find_rindex(int num, vector<int> &data, int st, int ed)
	{
		if ((ed == st) && (data[st] != num))return -1;
		int mid = (st + ed) / 2;
		if (data[mid] == num)
		{
			if (mid + 1 <= ed&&data[mid + 1] == num)
				return find_rindex(num, data, mid + 1, ed);
			return mid;
		}
		if (data[mid] > num)
			return find_rindex(num, data, st, mid - 1);
		else
			return find_rindex(num, data, mid + 1, ed);
	}
};


//ѭ���汾
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() == 0)return 0;
		int lindex = find_lindex(k, data);
		if (lindex == -1)return 0;
		int rindex = find_rindex(k, data);
		return rindex - lindex + 1;
	}

	//1.�ҵ������   2.�Ҳ��������  3.�������������                                                                             
	int find_lindex(int num, vector<int> &data)
	{
		int left = 0, right = data.size() - 1;
		while (1)
		{
			int mid = (left + right) / 2;
			if (left == right)//�����û�ҵ�
				return data[left] == num ? left : -1;
			if ((data[mid] == num&&mid - 1 >= left&&data[mid - 1] != num) || (data[mid] == num&&mid == left))
				return mid;
			if (data[mid] < num)
				left = mid + 1;
			else //�����ұ������������������һ����λ�ô���num���ڶ���λ�õ���num���Ҹ�λ����ߵ�λ��Ҳ����num
				right = mid - 1;
		}
	}
	int find_rindex(int num, vector<int> &data)
	{
		int left = 0, right = data.size() - 1;
		while (1)
		{
			int mid = (left + right) / 2;
			if (left == right)//��ֻʣ1��Ԫ��ʱ����ֱ���ж���
				return data[left] == num ? left : -1;
			//����������Է��أ�1����λ�õ�ֵ����num���Ҹ�λ���ұߵ�ֵ��Ϊnum 2����λ�õ�ֵ���ڲ��Ҹ�λ���Ѿ��������Ҷ�
			if ((data[mid] == num&&mid + 1 <= right&&data[mid + 1] != num) || (data[mid] == num&&mid == right))
				return mid;
			if (data[mid] > num)
				right = mid - 1;
			else //������������������������һ����λ��С��num���ڶ���λ�õ���num���Ҹ�λ���ұߵ�λ��Ҳ����num
				left = mid + 1;
		}
	}
};



int main()
{
	int a[] = {1,2,3,4,5,6,6,6,6,6,6,6,6,6,6,6,7,8,9,10};
	Solution mys;

	vector<int>va(&a[0],&a[sizeof(a)/sizeof(int)]);


	cout << mys.GetNumberOfK(va,6) << endl;


	cout << "end" << endl;
	system("pause");
}