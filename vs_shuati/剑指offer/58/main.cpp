#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){
	}
};

//最佳解法
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)return true;
		return isequal(pRoot->left, pRoot->right);
	}
	//判断两棵树是否相等:p1->val==p2->val并且p1的左子树等于p2的左子树并且p1的右子树等于p2的右子树
	//判断两棵树是否对称:p1->val==p2->val并且p1的左子树等于p2的右子树并且p1的右子树等于p2的左子树
	//总的来说就是“我的左等于你的右”
	//剑指offer解释：isequal实际上对于p1是“根左右”的先序遍历，而对于p2则是“根右左”的先序遍历，这种解释似乎更易理解
	bool isequal(TreeNode* p1, TreeNode* p2)
	{
		if (p1 == NULL&&p2 == NULL)
			return true;
		if (p1 == NULL || p2 == NULL)
			return false;
		if (p1->val == p2->val){
			return isequal(p1->left, p2->right) && isequal(p1->right, p2->left);
		}
		return false;
	}
};
int main()
{
	cout << "end" << endl;
	system("pause");
}