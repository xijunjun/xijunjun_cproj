#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){
	}
};
//����дһ��������һ�����غ��ӽڵ�ĺ�����Ȼ�������ҳ���һ�����غ��ӽڵ㲢��ӵ��µ�������ȥ
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