#include <iostream>
#include <vector>
#include<stack>
using namespace std;


struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
     }

};
//class LList{
//	ListNode *head = new ListNode(0);
//	ListNode *hence = head;
//	void insert(int num)
//	{
//		hence->next = new ListNode(num);
//		hence = hence->next;
//	}
//};
void append(ListNode * &phead,int num)
{
	if (phead == NULL)
	{
		phead = new ListNode(num);
	}
	else
	{
		ListNode* pnode=phead;
		while (pnode->next!=NULL)
		{
			pnode = pnode->next;
		}
		pnode->next = new ListNode(num);
	}
}
class Solution1 {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> list_vec;
		 stack <int>num_st;
		if (head == NULL)return list_vec;
		while (head!=NULL)
		{
			num_st.push(head->val);
			head= head->next;
		}
		while (!num_st.empty()){
				list_vec.push_back(num_st.top());
				num_st.pop();
		}
		return list_vec;
	}
};
class Solution {//µ›πÈ µœ÷
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> list_vec;
		if ( head== NULL)return list_vec;
		push2vec( head,list_vec);
		return list_vec;	
	}
	void  push2vec(ListNode* head, vector<int> &list_vec)
	{
		if (head->next != NULL){ push2vec(head->next, list_vec); }
		list_vec.push_back(head->val);
	}
};
int main()
{
	ListNode *chain=NULL ;
	for (int i = 0; i < 15; i++)
		append(chain, i);
	Solution mys;
	vector<int> list_vec=mys.printListFromTailToHead(chain);
	for (int i = 0; i < list_vec.size(); i++)
		cout << list_vec[i] << " ";

	cout << "end"<<endl;
	system("pause");
}