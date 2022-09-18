#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
void append(ListNode * &phead, int num)
{
	if (phead == NULL)
	{
		phead = new ListNode(num);
	}
	else
	{
		ListNode* pnode = phead;
		while (pnode->next != NULL)
		{
			pnode = pnode->next;
		}
		pnode->next = new ListNode(num);
	}
}
class Solution {//·ÇµÝ¹é
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* pHead = NULL, *rt = NULL;
		if (pHead1 == NULL)return pHead2;
		if (pHead2 == NULL)return pHead1;
		if (pHead1->val<pHead2->val){
			rt = pHead = pHead1;
			pHead1 = pHead1->next;
		}
		else {
			rt = pHead = pHead2;
			pHead2 = pHead2->next;
		}
		while (1){
			if (pHead1 == NULL){
				pHead->next = pHead2;
				break;
			}
			if (pHead2 == NULL){
				pHead->next = pHead1;
				break;
			}
			if (pHead1->val<pHead2->val){
				pHead->next = pHead1;
				pHead = pHead->next;
				pHead1 = pHead1->next;
			}
			else{
				pHead->next = pHead2;
				pHead = pHead->next;
				pHead2 = pHead2->next;
			}
		}
		return rt;
	}
};
class Solution1 {//µÝ¹éÊµÏÖ
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* pHead = NULL, *rt = NULL;
		if (pHead1 == NULL)return pHead2; 
		if (pHead2 == NULL)return pHead1; 
		if (pHead1->val<pHead2->val){
			pHead = pHead1;
			pHead1 = pHead1->next;
		}
		else {
		    pHead = pHead2;
		    pHead2 = pHead2->next;
		}
		pHead->next = Merge(pHead1,pHead2);
		return pHead;
	}
};
int main()
{
	ListNode *chain1=NULL,*chain2 = NULL;
	for (int i = 0; i < 15; i++)
	{
		if (i&1)append(chain1, i);
		else append(chain2, i);
	}
	Solution mys;
	ListNode *phead = mys.Merge(chain1, chain2);
	while (phead != NULL){
		cout << phead->val << " ";
		phead = phead->next;
	}
	cout << "end" << endl;
	system("pause");
}