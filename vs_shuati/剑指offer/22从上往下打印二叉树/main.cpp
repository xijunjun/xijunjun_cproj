#include <iostream>
#include <vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int>res;
		if (root == NULL)return res;
		queue<TreeNode* >q;
		q.push(root);
		while (!q.empty())
		{
			res.push_back(q.front()->val);
			if (q.front()->left != NULL){ q.push(q.front()->left); }
			if (q.front()->right != NULL){ q.push(q.front()->right); }
			q.pop();
		}
		return res;
	}
};
//重建二叉树
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	int length = pre.size();
	if (length == 0)return NULL;
	int root_val = pre[0];
	TreeNode* root = new TreeNode(root_val);
	if (length == 1)return root;

	vector<int> new_pre_l, new_vin_l, new_pre_r, new_vin_r;
	for (int i = 0; i < length; i++){
		if (vin[i] == root_val)break;
		else new_vin_l.push_back(vin[i]);
	}
	int left_size = new_vin_l.size();
	for (int i = 1; i <= left_size; i++)
		new_pre_l.push_back(pre[i]);
	for (int i = left_size + 1; i < length; i++){
		new_pre_r.push_back(pre[i]);
		new_vin_r.push_back(vin[i]);
	}
	int right_size = new_pre_r.size();

	if (left_size > 0)root->left = reConstructBinaryTree(new_pre_l, new_vin_l);
	if (right_size > 0)root->right = reConstructBinaryTree(new_pre_r, new_vin_r);
	return root;
}
int main()
{
	TreeNode* m_tree = NULL;
	int  v1[] = { 6, 8, 9, 2, 4, 7, 3 };
	int  v2[] = { 9, 8, 4, 2, 7, 6, 3 };
	vector<int> pre(&v1[0], &v1[sizeof(v1) / sizeof(int)]), vin(&v2[0], &v2[sizeof(v2) / sizeof(int)]);//使用数组初始化vector时，vector(start, end)注意end的地址是数组最后一个元素的后一个地址

	Solution mys;
	m_tree = reConstructBinaryTree(pre, vin);
	vector<int> res=mys.PrintFromTopToBottom(m_tree);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}

	cout << "end" << endl;
	system("pause");
}