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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL)return;
		if (pRoot->left == NULL&&pRoot->right == NULL)return;
		TreeNode *temp;
		temp = pRoot->left;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
		pRoot->left = pRoot->right;
		pRoot-> right = temp;
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
void print_btree2(TreeNode* root)
{
	queue<TreeNode*> node_q;
	node_q.push(root);
	TreeNode*rlast = root, *next_last = NULL;

	while (!node_q.empty())
	{
		cout << node_q.front()->val << " ";

		if (node_q.front()->left != NULL){
			node_q.push(node_q.front()->left);
			next_last = node_q.front()->left;
		}
		if (node_q.front()->right != NULL){
			node_q.push(node_q.front()->right);
			next_last = node_q.front()->right;
		}
		if (rlast == node_q.front()){
			cout << endl;
			rlast = next_last;
		}
		node_q.pop();
	}
}
int main()
{
	TreeNode* m_treeA = NULL;
	int  v1[] = { 6, 8, 9, 2, 4, 7, 3 };
	int  v2[] = { 9, 8, 4, 2, 7, 6, 3 };
	vector<int> pre(&v1[0], &v1[sizeof(v1) / sizeof(int)]), vin(&v2[0], &v2[sizeof(v2) / sizeof(int)]);
	m_treeA = reConstructBinaryTree(pre, vin);
	print_btree2(m_treeA);


	Solution mys;
	cout << "mirror:" << endl;
	mys.Mirror(m_treeA);
	print_btree2(m_treeA);
	cout << "end" << endl;
	system("pause");
}