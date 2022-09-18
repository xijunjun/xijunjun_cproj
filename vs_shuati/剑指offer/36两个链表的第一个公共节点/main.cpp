#include <iostream>
#include<stack>
using namespace std;


struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){
	}
};
//栈实现
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		stack<ListNode*>p1, p2;
		while (pHead1 != NULL) // 注意pHead1 != NULL和pHead1->next != NULL的区别，前者才能得到指向最后一个节点的指针
		{
			p1.push(pHead1);
			pHead1 = pHead1->next;
		}
		while (pHead2 != NULL)
		{
			p2.push(pHead2);
			pHead2 = pHead2->next;
		}
		ListNode* pcom = NULL;
		while (!(p1.size() == 0 || p2.size() == 0))
		{
			if (p1.top() != p2.top())break;
			pcom = p1.top();
			p1.pop();
			p2.pop();
		}
		return pcom;
	}
};

//计算长度

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		int len1 = GetLenth(pHead1), len2 = GetLenth(pHead2);
		ListNode* tpHead;
		int distance;
		if (len1 < len2){
			tpHead = pHead1;
			pHead1 = pHead2;//pHead1始终是大的
			pHead2 = tpHead;
			distance = len2;
			len2 = len1;
			len1 = distance;
		}
		distance = len1 - len2;
		while (distance--)
			pHead1 = pHead1->next;
		tpHead = NULL;
		while (len2--)
		{
			if (pHead1 == pHead2)
			{
				tpHead = pHead1;
				break;
			}
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return tpHead;
	}

	int GetLenth(ListNode* pHead1)
	{
		int cnt = 0;
		while (pHead1 != NULL)
		{
			cnt++;
			pHead1 = pHead1->next;
		}
		return cnt;
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

	cout << "end" << endl;
	system("pause");
}