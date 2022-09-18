#include <iostream>
using namespace std;
struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
}
};



//�����������������һ����ǰ�ڵ������ӽڵ㣬��������Ƚϼ򵥣�ֱ�ӷ���������������������ܵõ��ĵ�һ���ڵ㣻
//�ڶ�����ǰ�ڵ�û�����ӽڵ㣬����ǰ�ڵ��Ǹ��ڵ�����ӽڵ��򷵻ظ��ڵ㣬�����ǰ�ڵ�Ϊ���ڵ㲢ֱ����Ϊ���ڵ�����ӽڵ㡣
class Solution {
public:
	TreeLinkNode* get(TreeLinkNode* pNode)
	{
		if (pNode == NULL)return pNode;
		if (pNode->left != NULL)
			return get(pNode->left);
		return pNode;
	}
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)return NULL;
		if (pNode->right != NULL)
		{
			return get(pNode->right);
		}
		else
		{
			while (1)
			{
				if (pNode->next == NULL)
					return NULL;
				if (pNode->next->left == pNode)//�����ǰ�ڵ��Ǹ��ڵ����ڵ��򷵻ظ��ڵ㣬�����ǰ�ڵ��ƶ������ڵ�
					return pNode->next;
				pNode = pNode->next;
			}
		}
	}
};



int main()
{
	cout << "end" << endl;
	system("pause");
}