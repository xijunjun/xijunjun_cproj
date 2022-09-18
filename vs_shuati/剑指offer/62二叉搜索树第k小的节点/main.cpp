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


//在最简单的递归中序遍历二叉树中加入计数器即可
//一旦找到则停止递归调用
class Solution1 {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		int cnt = 0;
		TreeNode* rtv = NULL;
		recfuc(pRoot, rtv, k, cnt);
		return rtv;
	}
	void recfuc(TreeNode* pRoot, TreeNode*& rtv, int  k, int &cnt)
	{
		if (pRoot == NULL)//空节点则不改变
			return;
		recfuc(pRoot->left, rtv, k, cnt);
		if (++cnt == k){//一旦访问到第k小的节点则，记录下来，通过return，停止递归到右子树
			rtv = pRoot;
			return;
		}
		recfuc(pRoot->right, rtv, k, cnt);
	}
};
class Solution2 {
public:
	int cnt = 0;
	//由于只需要找出第k大的数，并不需要遍历完所以节点，所以对于任一节点来说，按照中序去判断，一旦找到就可以停止递归，停止压栈。
	//先根据普通的递归写出函数主体，函数返回值的含义是在pRoot树中找到的k节点。
	//所以每次递归调用就判断在子树中是否已找到k节点，若找到了，那么就不用再继续递归调用，直接访问在子树中找到的即可；如果没找到，还是得继续递归地按照根->右的顺序找。
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL)return NULL;
		TreeNode* node;
		node = KthNode(pRoot->left, k);
		if (node)return node;
		if (++cnt == k)return pRoot;
		node = KthNode(pRoot->right, k);
		if (node)return node;
		return NULL;
	}
};
//当node被找到了就不需要再找（再递归）了
class Solution3 {
public:
	int cnt = 0;
	TreeNode* node = NULL;
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL)return node;
		KthNode(pRoot->left, k);
		if (node)return node;
		if (++cnt == k)return node = pRoot;
		KthNode(pRoot->right, k);
		return node;
	}
};
int main()
{
	cout << "end" << endl;
	system("pause");
}