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

class Solution1 {//这个要付出内存代价，不太好
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL)return NULL;
		int cur = 0;
		ListNode**tp_list = new ListNode*[k];//注意二级指针的释放
		while (pListHead!= NULL){
			tp_list[cur++] = pListHead;
			pListHead = pListHead->next;
			if (cur == k)cur = 0;
		}
		ListNode* rt_val = tp_list[cur];
		delete tp_list;
		return rt_val;
	}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL)return NULL;
		ListNode *l, *r;
		l = r = pListHead;
		int cur = 0;
		for (; r != NULL; cur++)
		{
			if (cur >= k)
				l = l->next;
			r = r->next;
		}
		if (cur<k)return NULL;
		return l;
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
	
	cout<< mys.FindKthToTail(chain,16)->val;

	cout << "end" << endl;
	system("pause");
}