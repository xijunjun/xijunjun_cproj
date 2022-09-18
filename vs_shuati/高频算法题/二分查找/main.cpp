#include<iostream>
#include<queue>
using namespace std;

int b_search(int*a,int st,int ed,int n)
{
	if (st > ed )
		return -1;
	int mid = (st + ed)/2;
	if (a[mid] == n)
		return mid;
	if (a[mid > n])
		return b_search(a,st,mid-1,n);
	return b_search(a, mid+1,ed, n);
}


int LowerBound(vector<int>a,int k)
{
	int st = 0, ed = a.size() - 1,mid;
	while (1)
	{
		if (st == ed&&a[st]<k)return -1;
		mid = (st + ed) / 2;
		if (a[mid] >= k && (mid == 0 || k > a[mid - 1]))
			return mid;
		if (a[mid] >= k)
			ed=mid-1;
		else
			st=mid+1;
	}
}
int UpperBound(vector<int>a, int k)
{
	int st = 0, ed = a.size() - 1, mid;
	while (1)
	{
		if (st == ed&&a[st]<=k)return -1;
		mid = (st + ed) / 2;
		if (a[mid] > k && (mid == 0 || k >= a[mid - 1]))
			return mid;
		if (a[mid] > k)
			ed = mid - 1;
		else
			st = mid + 1;
	}
}


int getBound(vector<int>a, int k,bool islower=true)
{
	int st = 0, ed = a.size() - 1, mid;
	while (1)
	{
		if (st>ed)return -1;
		mid = (st + ed) / 2;
		if ((a[mid] > k || (islower&&a[mid] == k)) && (mid == 0 || k > a[mid - 1] || (!islower&&k == a[mid - 1])))
			return mid;
		if (a[mid] > k || (islower&&a[mid]==k))
			ed = mid - 1;
		else
			st = mid + 1;
	}
}
int main()
{
	int a[] = {0,1,2,2,2};
	vector <int>v(&a[0],&a[sizeof(a)/sizeof(int)]);
	cout <<getBound(v, 1,false);

	//cout << b_search(a, 0, 7, 8) << endl;
	system("pause");
}