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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL)return false;
		return judge(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
	bool judge(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == NULL || pRoot1 == NULL)return false;
		if (pRoot2->val != pRoot1->val)return false;
		if (pRoot2->left != NULL)
		{
			if (pRoot1->left == NULL)return false;
			if (!judge(pRoot1->left, pRoot2->left))return false;
		}
		if (pRoot2->right != NULL)
		{
			if (pRoot1->right == NULL)return false;
			if (!judge(pRoot1->right, pRoot2->right))return false;
		}
		return true;
	}
};
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
	TreeNode* m_treeA = NULL, *m_treeB = NULL;
	int  v1[] = { 6, 8, 9, 2, 4, 7, 3 };
	int  v2[] = { 9, 8, 4, 2, 7, 6, 3 };
	vector<int> pre(&v1[0], &v1[sizeof(v1)/sizeof(int)]), vin(&v2[0], &v2[sizeof(v2)/sizeof(int)]);
	m_treeA =reConstructBinaryTree(pre, vin);

	int  v3[] = {  8, 9, 1};
	int  v4[] = { 9, 8, 1};
	vector<int> pre2(&v3[0], &v3[sizeof(v3) / sizeof(int)]), vin2(&v4[0], &v4[sizeof(v4) / sizeof(int)]);
	m_treeB = reConstructBinaryTree(pre2, vin2);

	Solution mys;
	cout<<mys.HasSubtree(m_treeA, m_treeB);

	cout << "end" << endl;
	system("pause");
}