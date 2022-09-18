#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		queue<int> q1, q2;
		for (int i = 0; i < array.size(); i++){
			if (array[i] & 1){
				q1.push(array[i]);
			}
			else{
				q2.push(array[i]);
			}
		}
		array.clear();
		while (!q1.empty()){
			array.push_back(q1.front());
			q1.pop();
		}
		while (!q2.empty()){
			array.push_back(q2.front());
			q2.pop();
		}
	}
};
int main()
{
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> veca(&a[0],&a[sizeof(a)/sizeof(int)]);
	Solution mys;
	mys.reOrderArray(veca);
	for (int i = 0; i <veca.size(); i++){
		cout << veca [i]<< " ";
	}

	cout << "end" << endl;
	system("pause");
}