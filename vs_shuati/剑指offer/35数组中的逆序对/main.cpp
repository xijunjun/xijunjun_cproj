#include <iostream>
#include<vector>
using namespace std;

//本题的基本思路：分治，在合并子问题时有一定规律，可减少比较次数，进而降低复杂度。
//分治过后要思考合适的合并策略，也就是计算两个有序数组合并起来的逆序对。
//本题在实现上参考归并排序，只需在合并子数组时对每个数判断其与另外子数组构成的逆序对个数


//从左向右合并
class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.size() == 0)
			return 0;
		vector<int>temp(data);
		unsigned long long cnt = 0;//注意cnt的类型，看清题目的取值范围
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
			if (t1 > mid_index)//左数组到头
				a[i] = b[t2++];
			else if (t2>ed)//右数组到头
				a[i] = b[t1++];
			else//从左到右确定合并为升序数组，所以依次取最小的数，比较过程中，一旦右子数组有数小于左子数组则产生逆序对，产生逆序对的数量为左子数组剩下的数的数量，因为
				//因为子数组都为升序，若右子数组当前数小于左子数组当前数，则右子数组当前数小于左子数组剩下的所有数。
				a[i] = b[t1] < b[t2] ? b[t1++] : (cnt += mid_index - t1 + 1, b[t2++]);//注意此行的括号,逗号运算符的优先级最低
		}
	}

};

//从右往左合并2
class Solution2 {
public:
	int InversePairs(vector<int> data) {
		if (data.size() == 0)
			return 0;
		vector<int>temp(data);
		unsigned long long cnt = 0;//注意cnt的类型，看清题目的取值范围
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
			if (t1 <st)//左数组到头
				a[i] = b[t2--];
			else if (t2 <mid_index + 1)//右数组到头
				a[i] = b[t1--];
			else
				a[i] = b[t1] > b[t2] ? (cnt += t2 - (mid_index + 1) + 1, b[t1--]) : b[t2--];
		}
	}
};




//归并排序
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
	//k = (3<2) ? 1, 2 : 3,4;//逗号运算符的优先级最低执行顺序为   ((3<2) ? 1, 2 : 3),4
	//cout << "k: " << k<< endl;


	cout << "end" << endl;
	system("pause");
}