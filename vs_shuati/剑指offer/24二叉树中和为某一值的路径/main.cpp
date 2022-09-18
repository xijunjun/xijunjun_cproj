#include <iostream>
#include <vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int> >res;
		vector<int>route;
		int sum = 0;
		dfs_visit(root, expectNumber, sum, route, res);
		return res;
	}
	void dfs_visit(TreeNode* root, int expectNumber, int sum, vector<int>&route, vector<vector<int> >&res)
	{
		if (root == NULL)return;
		route.push_back(root->val);
		sum += root->val;
		if (root->left == NULL&&root->right == NULL&&sum == expectNumber)res.push_back(route);
		if (root->left != NULL)dfs_visit(root->left, expectNumber, sum, route, res);
		if (root->right != NULL)dfs_visit(root->right, expectNumber, sum, route, res);
		route.pop_back();
	}
};
/*
总结：
由于涉及到根到叶节点的路径，此题宜采用DFS（前序遍历）对二叉树进行遍历，这便于在程序中记录路径。此处采用递归实现DFS，
为了得到从根节点到当前节点的路径，使用 vector<int>&route作为递归函数公共的容器来记录根节点到当前节点前一个节点的路径，
同时使用int sum 传递根节点到当前节点前一个节点的和。
*/