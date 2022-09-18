#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;

struct CPoint
{
	int x,y;
};
struct CLine
{
	CPoint p1,p2;
};


bool judge(CPoint &a, CPoint &b, CPoint &c, CPoint &d)
{
	if (!(min(a.x, b.x) <= max(c.x, d.x) && min(c.y, d.y) <= max(a.y, b.y) && min(c.x, d.x) <= max(a.x, b.x) && min(a.y, b.y) <= max(c.y, d.y)))
		return false;
	double u, v, w, z;
	u = (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
	v = (d.x - a.x)*(b.y - a.y) - (b.x - a.x)*(d.y - a.y);
	w = (a.x - c.x)*(d.y - c.y) - (d.x - c.x)*(a.y - c.y);
	z = (b.x - c.x)*(d.y - c.y) - (d.x - c.x)*(b.y - c.y);
	return (u*v <= 0 && w*z <= 0);
}

int serch_id(vector<CLine>a, int  k, vector<int>rec)
{
	int cnt = 0;
	k--;
	for (int i = 0; i < a.size();i++)
	{
		if (k == i)continue;
		if (judge(a[i].p1, a[i].p2, a[k].p1, a[k].p2) )
			return count(rec.begin(), rec.end(), rec[i]);
	}
	return 0;
}

void addline(vector<CLine>&a, CLine &tmp, vector<int>&rec)
{
	
	int cnt = 0;
	rec.push_back(a.size());
	a.push_back(tmp);
	int ed = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (judge(a[i].p1, a[i].p2, tmp.p1, tmp.p2))
		{
			if (!ed){
				rec[rec.size() - 1] = rec[i];
				ed = 1;
			}
			else
				rec[i] = rec[rec.size() - 1];
		}
	}
	for (int j = a.size()-1; j >=0; j--)
	{
		ed = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (judge(a[i].p1, a[i].p2, a[j].p1, a[j].p2))
			{
				if (!ed){
					rec[rec.size() - 1] = rec[i];
					ed = 1;
				}
				else
					rec[i] = rec[rec.size() - 1];
			}
		}
	}
}


int main(){
    #define CIN myin
	ifstream myin("input.txt");
	int t, n;
	CIN >> t ;
	
	for (int j = 0; j < t; j++)
	{
		vector<CLine>a;
		vector<int>rec;
		CLine tmp;
		CIN >> n;
		for (int i = 0; i < n; i++)
		{
			char flag;
			CIN >> flag;
			if (flag == 'T'){
				CIN >> tmp.p1.x >> tmp.p1.y >> tmp.p2.x >> tmp.p2.y;
				//a.push_back(tmp);
				addline(a, tmp,rec);
			}
			else{
				int k;
				CIN >> k;
				cout << serch_id(a, k, rec) << endl;
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}