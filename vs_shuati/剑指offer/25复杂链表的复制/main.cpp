#include <iostream>
#include <vector>
#include<queue>
using namespace std;
/*
�ܽ᣺
1.������ѵ�����������ڵ�A1�����ָ��ĸ�ֵ���½ڵ�A1�е�rand��Ҫͨ��A->rand����ȡ����A->rand��Ӧ�µĽڵ�ĵ�ַ�ǲ�֪���ģ�
����ֻ���Ȳ���rand������������
2.���������������ڵ��е�rand��A1->rand�Ǹ���A->rand����ȡ��A1->randָ��B1��A->randָ��B��������Ҫ����B�õ�B1��һ����������
�����������ʱ����һ����ϣ������¼�¾ɽڵ�Ķ�Ӧ��ϵ��Ȼ����ݹ�ϣ�����������ڵ��е�rand�����ǹ����ϣ��Ҫ�������ٿռ����
��ʱ����ۡ�
3.��ָoffer�н�����һ������ķ��������µĽڵ�ŵ�ԭ�����Ӧ�ڵ�ĺ��棬�ϳ�һ�����������Ǹ���B1=B->B��A->A1->B->B1->C->C1��
������A1->rand=A->rand->next;�������½ڵ��е�randֵ���ٽ����������������ȡ������
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
class Solution {//�����
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