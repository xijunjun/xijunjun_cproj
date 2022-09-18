#include <iostream>
using namespace std;
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
/*
思路：将二叉搜索树convert为双向链表，尝试递归解决。递归关系：当访问到节点root时，root->left与转换后的左子树链表完成互指，
root->right与转换后的右子树链表完成互指。根据题意，令返回值为最左节点，若root存在左子树，也就是左子树链表的指针，当不存
在左子树，返回根节点指针。由于返回的指针是最左的，而root->left要指向左子树链表最右的指针，所以连接左子树链表时，要将返回
的指针移到最右。而root->right就是连接右子树最左指针，可直接连接。
*/
class Solution {
public:
	TreeNode*  Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)return NULL;
		if (pRootOfTree->right != NULL){
			pRootOfTree->right = Convert(pRootOfTree->right);
			pRootOfTree->right->left = pRootOfTree;
		}
		if (pRootOfTree->left != NULL){
			TreeNode* pmin = Convert(pRootOfTree->left);
			TreeNode*pmax = pmin;
			while (pmax->right != NULL)pmax = pmax->right;
			pRootOfTree->left = pmax;
			pRootOfTree->left->right = pRootOfTree;
			return pmin;
		}
		return pRootOfTree;
	}
};

/*
中序遍历思路（建议解法）：
中序遍历对节点的访问顺序和转换完链表从左到右的顺序是一样的。所以在中序遍历时完成相邻两个节点的互指即可。具体做法是把前一个节点记录下来然后pre->right = cur; cur->left = pre。
*/

class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr) return nullptr;
		TreeNode* pre = nullptr;
		convertHelper(pRootOfTree, pre);
		TreeNode* res = pRootOfTree;
		while (res->left)
			res = res->left;
		return res;
	}
	void convertHelper(TreeNode* cur, TreeNode*& pre)
	{
		if (cur == nullptr) return;
		convertHelper(cur->left, pre);
		cur->left = pre;
		if (pre) pre->right = cur;
		pre = cur;
		convertHelper(cur->right, pre);
	}
};