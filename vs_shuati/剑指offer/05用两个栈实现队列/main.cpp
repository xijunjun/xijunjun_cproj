#include <iostream>
#include <stack>
using namespace std;

class Solution1//这是个很低效率的实现，每次压入新元素都会操作所有元素
{
public:
	void push(int node) {
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		stack1.push(node);
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}

	int pop() {
		if (stack2.empty())return -1; 
		int val = stack2.top();
		stack2.pop();
		return val;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
class Solution
{
public:
	void push(int node) {
			stack1.push(node);
	}
	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				int val = stack1.top();
				stack2.push(val);
				stack1.pop();
			}
		}
		if (stack2.empty())
		{
			return -1;
		}
		else
		{
			int val = stack2.top();
			stack2.pop();
			return val;
		}
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};
int main()
{
	Solution mys;
	for (int i = 0; i < 5; i++){
		mys.push(i);
	}
	for (int i = 0; i < 5; i++){
		cout<<mys.pop()<<" ";
	}

	cout << "end" << endl;
	system("pause");
}