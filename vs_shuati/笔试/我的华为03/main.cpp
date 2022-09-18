#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;


struct Info{
	int seq, type, num;
};
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	#define CIN myin
	ifstream myin("input.txt");
	int n;
	CIN >> n;
	int last = -1;
	vector<vector<int>>res;
	for (int i = 0; i < n; i++)
	{
		int k;
		CIN >> hex >> k;
		if (k == 0)
		{
				Info tmp;
				CIN >> tmp.seq;
				if (last != -1 && tmp.seq != last + 1 && tmp.seq + 16 != last + 1)
				{
					cout << "FALSE";
					return 0;
				}
				int temp;
				CIN >> temp;
				tmp.type = temp >> 4;
				tmp.num = temp &0x0f;
				vector<int>tpv(tmp.num);
				last = tmp.num;
				for (int i = 0; i <tmp.num; i++)
					CIN>>tpv[i];
				if (tmp.type == 2)
					sort(tpv.begin(),tpv.end());
				else
					sort(tpv.begin(), tpv.end(),cmp);
				res.push_back(tpv);

				

		}
		//cout << k << endl;
	}
	for (auto it : res)
	{
		for (auto it2 : it)
			cout <<"0x"<< hex<<it2 << " ";
	}


	system("pause");
	return 0;
}