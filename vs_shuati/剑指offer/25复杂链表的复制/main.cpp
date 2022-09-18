#include <iostream>
#include <vector>
#include<queue>
using namespace std;
/*
总结：
1.本题的难点在于新链表节点A1中随机指针的赋值，新节点A1中的rand需要通过A->rand来获取。而A->rand对应新的节点的地址是不知道的，
所以只能先不管rand，构建新链表。
2.接下来解决新链表节点中的rand，A1->rand是根据A->rand来获取，A1->rand指向B1，A->rand指向B，所以需要根据B得到B1，一种做法是在
构建新链表的时候用一个哈希表来记录新旧节点的对应关系。然后根据哈希表更新新链表节点中的rand。但是构造哈希表要付出不少空间代价
和时间代价。
3.剑指offer中介绍了一种巧妙的方法：把新的节点放到原链表对应节点的后面，合成一个新链表。于是根据B1=B->B，A->A1->B->B1->C->C1，
所以有A1->rand=A->rand->next;更新完新节点中的rand值，再将新链表从总链表中取出来。
*/
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution1 {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)return NULL;
		RandomListNode *pclone = pHead, *pori = pHead, *pcopy;
		while (pHead != NULL)
		{
			RandomListNode *ptemp = pHead->next;
			pHead->next = new RandomListNode(pHead->label);
			pHead->next->next = ptemp;
			pHead->next->random = pHead->random;
			pHead = ptemp;
		}
		pHead = pclone->next;
		while (1)
		{
			if (pHead->random != NULL)
				pHead->random = pHead->random->next;
			if (pHead->next == NULL)break;
			pHead = pHead->next->next;
		}
		pHead = pclone;
		pclone = pHead->next;
		pcopy = pclone;
		pHead = pclone->next;
		while (pHead != NULL)
		{
			pori->next = pHead;
			pori = pori->next;
			pHead = pHead->next;
			pclone->next = pHead;
			pclone = pclone->next;
			pHead = pHead->next;
		}
		pori->next = NULL;
		return pcopy;
	}
};
class Solution {//精简版
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)return NULL;
		RandomListNode *pclone = pHead;
		while (pHead != NULL)
		{
			RandomListNode *ptemp = pHead->next;
			pHead->next = new RandomListNode(pHead->label);
			pHead->next->next = ptemp;
			pHead->next->random = pHead->random;
			pHead = ptemp;
		}
		pHead = pclone->next;
		while (1)
		{
			if (pHead->random != NULL)
				pHead->random = pHead->random->next;
			if (pHead->next == NULL)break;
			pHead = pHead->next->next;
		}
		pHead = pclone;
		pclone = pHead->next;
		while (pHead->next != NULL)
		{
			RandomListNode *ptemp = pHead->next;
			pHead->next = pHead->next->next;
			pHead = ptemp;
		}
		return pclone;
	}
};