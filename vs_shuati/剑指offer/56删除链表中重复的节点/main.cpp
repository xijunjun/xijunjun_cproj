#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){
	}
};
//首先写一个查找下一个非重合子节点的函数。然后依次找出下一个非重合子节点并添加到新的链表中去
class Solution {
public:
	ListNode* next_sigle_node(ListNode* pHead)
	{
		if (pHead == NULL)return pHead;
		if (pHead->next == NULL || pHead->val != pHead->next->val)
			return pHead;
	    while (pHead->next != NULL&&pHead->val == pHead->next->val)
	    {
		 pHead->next = pHead->next->next;
		}
		return next_sigle_node(pHead->next);
	}
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)return pHead;
		ListNode* p, *ph;
		p = next_sigle_node(pHead);
		ph = p;
		while (p != NULL)
		{
			p->next = next_sigle_node(p->next);
			p = p->next;
		}
		return ph;
	}
};
int main()
{

}