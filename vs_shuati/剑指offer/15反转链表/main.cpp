
#include <iostream>

using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {//递归实现
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead->next == NULL || pHead == NULL)return pHead;
		ListNode* revlist = ReverseList(pHead->next);
		pHead->next->next = pHead;
		pHead->next = NULL;
		return revlist;
	}
};
class Solution1 {//遍历实现
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode*pcur = pHead, *pfront1 = NULL, *tp = NULL;
		while (pcur != NULL){
			tp = pcur->next;
			pcur->next = pfront1;
			pfront1 = pcur;
			pcur = tp;
		}
		return pfront1;
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
int main()
{
	ListNode *chain = NULL;
	for (int i = 0; i < 15; i++)
		append(chain, i);
	Solution mys;
	ListNode *phead = mys.ReverseList(chain);
	while (phead != NULL){
		cout << phead->val << " ";
		phead = phead->next;
	}
	cout << "end" << endl;
	system("pause");
}