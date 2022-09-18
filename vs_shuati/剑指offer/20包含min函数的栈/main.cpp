#include <iostream>
using namespace std;

class Solution {
public:
	struct ListNode{
		struct ListNode*next;
		int val;
		ListNode(int x, ListNode*p) :next(p), val(x)
		{}
	};
	ListNode* head = NULL;
	void push(int value) {
		head = new ListNode(value,head);
	}
	void pop() {
		ListNode *temp =head;
		if (head != NULL){
			head = head->next;
			delete temp;
		}
	}
	int top() {
		if (head == NULL)return 0;
		return head->val;
	}
	int min() {
		if (head == NULL)return -1;
		ListNode* p = head, *pmin = head;
		while (p != NULL){
			if (p->val < pmin->val)pmin = p;
			p = p->next;
		}
		return pmin->val;
	}
};
int main()
{
	Solution stk;
	
	for (int i = 0; i < 10; i++)
	{ 
		stk.push(i);
	}
	stk.pop();
	stk.pop();
	stk.pop();
	cout << stk.min()<<endl;

	cout << "end" << endl;
	system("pause");
}