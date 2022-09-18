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



//分两种情况分析，第一：当前节点有右子节点，这种情况比较简单，直接返回右子树按照中序遍历能得到的第一个节点；
//第二：当前节点没有右子节点，若当前节点是父节点的左子节点则返回父节点，否则令当前节点为父节点并直到成为父节点的左子节点。
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
				if (pNode->next->left == pNode)//如果当前节点是父节点的左节点则返回父节点，否则令当前节点移动到父节点
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