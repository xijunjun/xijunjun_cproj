#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<deque>
using namespace std;
void fun(int A,int B)
{
	int res = 0;
	if (A + 6 * B >= 0){
		cout << 17 * B << endl;
	}
	else{
		int i = 1;
		int tmp;
		while (i < 7){
			tmp = i*B + (7 - i)*A;
			if (tmp < 0)
				break;
			i++;
		}
		if (i <= 4)res = tmp * 2 + A * 3;
		else if (i == 5)res = tmp * 2 + A * 2 + B;
		else if (i == 6)res = tmp * 2 + A + B * 2;
		cout << res << endl;
	}
}

int main()
{
	int A,B;
	cin >> A>>B;

	int sum7=0,sum = 0;
	int k = 1;
	deque<int>dq;
	while (1)
	{ 
		dq.push_back(B);
		if (B*k + A*(7 - k) < 0)break;
		k++;
	}
	cout << k << endl;
	for (int i = 7-k-1; i >= 0;i--)
		dq.push_back(A);
	sum = sum7 = B*k + A*(7 - k);
	for (auto it = dq.rbegin(); it != dq.rend();it++)
		cout << *it << ",";
	for (int i = 7; i<17; i++)
	{
		sum7 -= dq.back();
		dq.pop_back();
		if (sum7+A >= 0){
			sum7 += B;
			dq.push_front(B);
		}
		else {
			dq.push_front(A);
			sum7 += A;
		}
		sum +=dq.front();
		cout << dq.front() << ",";
	}
	cout<<endl<<sum<<endl;
	fun( A,  B);
	system("pause");
	return 0;
}