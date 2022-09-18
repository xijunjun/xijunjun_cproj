#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//直接版
//关键词：两个堆
//核心思路：使用一个大顶堆和一个小顶堆来维护整体的数据，在压入堆时交替入堆以维持两个堆的大小差距小于等于1，
//必须保证小顶堆中堆顶值大于大顶堆堆顶值，所以入堆时需分别考虑，当压入小顶堆时，选择num和大顶堆堆顶中大的那一个压入堆中，
//若压入的是num，直接入堆即可，否则压入大顶堆堆顶，同时用num替换掉原来的大顶堆堆顶，并调整大顶堆。
class Solution {
public:
	int cnt = 0;
	vector <int> maxheap, minheap;
	void insert2max(int num)//向堆中插入元素
	{
		maxheap.push_back(num);
		int inde = maxheap.size() - 1;
		while (1)
		{
			if (inde <= 0)break;
			if (maxheap[(inde - 1) / 2]<maxheap[inde])
				swap(maxheap[(inde - 1) / 2], maxheap[inde]);
			else break;
			inde = (inde - 1) / 2;
		}
	}
	void adjmax(int num)//更换堆顶
	{
		maxheap[0] = num;
		int ind = 0;
		while (1)
		{
			int nextind = 2 * ind + 1;
			if (nextind>maxheap.size() - 1)break;
			if (nextind + 1 <= maxheap.size() - 1 && maxheap[nextind + 1]>maxheap[nextind])
				nextind++;
			if (maxheap[ind]<maxheap[nextind])
				swap(maxheap[ind], maxheap[nextind]);
			else break;
			ind = nextind;
		}
	}

	void insert2min(int num)//向堆中插入元素
	{
		minheap.push_back(num);
		int inde = minheap.size() - 1;
		while (1)
		{
			if (inde <= 0)break;
			if (minheap[(inde - 1) / 2]>minheap[inde])
				swap(minheap[(inde - 1) / 2], minheap[inde]);
			else break;
			inde = (inde - 1) / 2;
		}
	}
	void adjmin(int num)//更换堆顶
	{
		minheap[0] = num;
		int ind = 0;
		while (1)
		{
			int nextind = 2 * ind + 1;
			if (nextind>minheap.size() - 1)break;
			if (nextind + 1 <= minheap.size() - 1 && minheap[nextind + 1]<minheap[nextind])
				nextind++;
			if (minheap[ind]>minheap[nextind])
				swap(minheap[ind], minheap[nextind]);
			else break;
			ind = nextind;
		}
	}
	void Insert(int num)
	{
		if (cnt++ % 2){
			if (minheap.size() != 0 && num>minheap[0])//插入大顶堆的应该是minheap[0]与num中小的那一个
			{
				insert2max(minheap[0]);
				adjmin(num);
			}
			else insert2max(num);
		}
		else{
			if (maxheap.size() != 0 && maxheap[0]>num)//插入小顶堆的应该是maxheap[0]与num中大的那一个
			{
				insert2min(maxheap[0]);
				adjmax(num);
			}
			else insert2min(num);
		}
	}
	double GetMedian()
	{
		if (cnt == 0)return NULL;
		if (cnt % 2)return minheap[0];
		else return double((minheap[0] + maxheap[0])*0.5);
	}

};
//精简版
class Solution2 {
public:
	int cnt = 0;
	vector <int> maxheap, minheap;
	void insert2heap(vector <int>&heap,int num,bool ismin)//向堆中插入元素
	{
		heap.push_back(num);
		int inde = heap.size() - 1;
		while (1)
		{
			if (inde <= 0)break;
			if (ismin^(heap[(inde - 1) / 2]<heap[inde]))
				swap(heap[(inde - 1) / 2], heap[inde]);
			else break;
			inde = (inde - 1) / 2;
		}
	}
	void adjheap(vector <int>&heap, int num, bool ismin)//更换堆顶
	{
		heap[0] = num;
		int ind = 0;
		while (1)
		{
			int nextind = 2 * ind + 1;
			if (nextind>heap.size() - 1)break;
			if (nextind + 1 <= heap.size() - 1 && ((heap[nextind + 1]>heap[nextind])^ismin))
				nextind++;
			if ((heap[ind]<heap[nextind])^ismin)
				swap(heap[ind], heap[nextind]);
			else break;
			ind = nextind;
		}
	}
	void Insert(int num)
	{
		if (cnt++ % 2){
			if (minheap.size() != 0 && num>minheap[0])//插入大顶堆的应该是minheap[0]与num中小的那一个
			{
				insert2heap(maxheap, minheap[0], 0);
				adjheap(minheap,num,1);
			}
			else insert2heap(maxheap, num, 0);
		}
		else{
			if (maxheap.size() != 0 && maxheap[0]>num)//插入小顶堆的应该是maxheap[0]与num中大的那一个
			{
				insert2heap(minheap, maxheap[0], 1);
				adjheap(maxheap, num, 0);
			}
			else insert2heap(minheap, num, 1);
		}
	}
	double GetMedian()
	{
		if (cnt == 0)return NULL;
		if (cnt % 2)return minheap[0];
		else return double((minheap[0] + maxheap[0])*0.5);
	}
};

class Solution3 {
	priority_queue<int, vector<int>, less<int> > p;
	priority_queue<int, vector<int>, greater<int> > q;

public:
	void Insert(int num){
		if (p.empty() || num <= p.top()) p.push(num);
		else q.push(num);
		if (p.size() == q.size() + 2) q.push(p.top()), p.pop();
		if (p.size() + 1 == q.size()) p.push(q.top()), q.pop();
	}
	double GetMedian(){
		return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
	}
};
int main()
{
	//vector <int> maxheap;
	//int a[] = {4,5,3,0,1,7,2,6};
	//for (int i = 0; i < 8;i++)
	//{
	//	insert2max(maxheap, a[i]);
	//}
	//for (auto it = maxheap.begin(); it != maxheap.end(); it++)
	//{
	//	cout << *it << ",";
	//}
	//

	cout << "end" << endl;
	system("pause");
}