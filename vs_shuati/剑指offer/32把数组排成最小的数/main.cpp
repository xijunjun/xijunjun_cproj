#include <iostream>
#include <vector>
#include <string>
using namespace std;

//˼·�������鶼��1λ��ʱ��ֱ�Ӷ��������������������������ɣ������鶼����λ���λ��ʱ��ͬ��
//��ô�������е�λ����ͬʱ�Ƿ�Ҳ���ԣ��ǿ��Եġ�����������⣬��λ���ٵ���չ��ͬ����λ��������123��9��14��
//����չΪ123��900��140����չ����С���Ԫ�ص��Ⱥ�˳�򲢲��ᷢ���ı䡣���Զ������еİ�����չ��Ľ��бȽ�����
//���ɡ�
class Solution {
public:
	bool isAsmall(int a, int b)
	{
		string ab, ba;
		return to_string(a) + to_string(b)<to_string(b) + to_string(a);
	}
	int partition(vector<int>&p, int st, int ed)
	{
		swap(p[st], p[ed]);
		int insert_index = st;
		for (int i = st; i <= ed - 1; i++)
		{
			//if (p[i] < p[ed])
			if (isAsmall(p[i], p[ed]))
				swap(p[insert_index++], p[i]);
		}
		swap(p[insert_index], p[ed]);
		return insert_index;
	}
	void quick_sort(vector<int>&p, int st, int ed)
	{
		if (ed <= st)return;
		int index = partition(p, st, ed);
		quick_sort(p, st, index);
		quick_sort(p, index + 1, ed);
	}
	string PrintMinNumber(vector<int> numbers) {
		quick_sort(numbers, 0, numbers.size()-1);
		string rt_str;
		for (int i = 0; i < numbers.size();i++)
		{
			rt_str += to_string(numbers[i]);
		}
		return rt_str;
	}

};


int main()
{
	Solution mys;
	int arr[] = {2,14,3,1,9};
	vector<int>arrrv(&arr[0],&arr[5]);
	//quick_sort(arr, 0, 4);

	cout << mys.PrintMinNumber(arrrv) << endl;

	cout << "end" << endl;
	system("pause");
}