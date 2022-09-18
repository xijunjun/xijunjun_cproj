#include<iostream>
using namespace std;


struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){
	}
};

//最优解法，第一步通过快慢指针相遇，第二步新建一个慢指针等于表头，两个慢指针同时走直到相遇。
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return NULL;
		ListNode *pfast = pHead, *pslow = pHead;
		while (1)
		{
			if (pfast == NULL || pfast->next == NULL)
				return NULL;
			pfast = pfast->next->next;
			pslow = pslow->next;
			if (pfast == pslow)
				break;
		}
		pfast = pHead;
		while (1)//注意此处判断和next的顺序!!!
		{
			if (pfast == pslow)
				return pfast;
			pfast = pfast->next;
			pslow = pslow->next;
		}
	}
};
//求环长解法，
class Solution2 {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)return NULL;
		ListNode *pfast = pHead, *pslow = pHead, *pcom = NULL;
		while (1)
		{
			if (pfast == NULL || pfast->next == NULL)
				return NULL;
			pfast = pfast->next->next;
			pslow = pslow->next;
			if (pfast == pslow)
			{
				pcom = pfast;
				break;
			}
		}
		pslow = pslow->next;
		int n = 1;
		while (1)
		{
			if (pslow == pcom)
				break;
			pslow = pslow->next;
			n++;
		}
		pslow = pHead;
		pfast = pHead;
		while (n--)
			pfast = pfast->next;
		while (1)
		{
			if (pfast == pslow)
				return pfast;
			pfast = pfast->next;
			pslow = pslow->next;
		}
	}
};
int main()
{

}