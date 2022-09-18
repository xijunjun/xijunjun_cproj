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
�ܽ᣺
�����漰������Ҷ�ڵ��·���������˲���DFS��ǰ��������Զ��������б�����������ڳ����м�¼·�����˴����õݹ�ʵ��DFS��
Ϊ�˵õ��Ӹ��ڵ㵽��ǰ�ڵ��·����ʹ�� vector<int>&route��Ϊ�ݹ麯����������������¼���ڵ㵽��ǰ�ڵ�ǰһ���ڵ��·����
ͬʱʹ��int sum ���ݸ��ڵ㵽��ǰ�ڵ�ǰһ���ڵ�ĺ͡�
*/