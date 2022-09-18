#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;
using namespace std;

const double eps = 1e-8;
struct CPoint
{
	double x, y;
};
int dcmp(double x)
{
	if (x<-eps) return -1;
	else   return (x>eps);
}
double cross(CPoint p0, CPoint p1, CPoint p2)
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}
double dot(CPoint p0, CPoint p1, CPoint p2)
{
	return (p1.x - p0.x)*(p2.x - p0.x) + (p1.y - p0.y)*(p2.y - p0.y);
}
int PointOnSegment(CPoint p0, CPoint p1, CPoint p2)
{
	return dcmp(cross(p0, p1, p2)) == 0 && dcmp(dot(p0, p1, p2)) <= 0;
}
int PointInPolygon(CPoint cp, vector<CPoint>p, int n)
{
	int i, k, d1, d2, wn = 0;
	//  double sum=0;
	p[n] = p[0];
	for (i = 0; i<n; i++)
	{
		if (PointOnSegment(cp, p[i], p[i + 1])) return 2;
		k = dcmp(cross(p[i], p[i + 1], cp));
		d1 = dcmp(p[i + 0].y - cp.y);
		d2 = dcmp(p[i + 1].y - cp.y);
		if (k>0 && d1 <= 0 && d2>0)wn++;
		if (k<0 && d2 <= 0 && d1>0)wn--;
	}
	return wn != 0;
}
vector<double>split_str(string &s, string p)
{
	vector<double>res;
	string subtmp;
	int st = 0, ed = s.size();
	while (1)
	{
		int i = s.find_first_of(p, st);
		if (i == string::npos&&ed == -1)
			break;
		if ((i == string::npos || i == ed) && ed != -1){
			i = ed;
			ed = -1;
		}
		subtmp = s.substr(st, i - st);
		if (!subtmp.empty())
			res.push_back(stod(subtmp));
		st = i + 1;
	}
	return res;
}
int main()
{
	//#define CIN myin
	//ifstream myin("input.txt");
	//int n, m;
	//string s1, s2;
	//CIN >> n >> s1 >> m >> s2;
	//vector<double> rct = split_str(s1, ","), pts = split_str(s2, ",");
	//vector<CPoint>point(n+1);
	//for (int i = 0; i < n; i++)
	//{
	//	point[i].x = rct[2*i];
	//	point[i].y = rct[2*i+1];
	//}
	//CPoint temp;
	//string res = "";
	//for (int j = 0; j < m; j++)
	//{
	//	char buffer[200];
	//	temp.x = pts[2*j];
	//	temp.y = pts[2 * j+1];
	//	if (PointInPolygon(temp, point, n) == 1){
	//		sprintf(buffer, "(%.2f,%.2f) ", pts[2 * j], pts[2 * j + 1]);
	//		res += string(buffer);
	//	}
	//}
	//res.pop_back();
	//cout << res;
	char str[] = "hello";
	cout <<sizeof(str);



	system("pause");
	return 0;
}
