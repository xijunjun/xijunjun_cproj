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
class Solution {//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())return false;

		vector<int> ls, rs;
		int end_cur = sequence.size() - 1, rcur = sequence.size();//这里注意
		for (int i = 0; i < end_cur; i++)
		{
			if (sequence[i] < sequence[end_cur])ls.push_back(sequence[i]);
			else { rcur = i + 1; break; }
		}
		for (int i = rcur; i < end_cur; i++)
		{
			rs.push_back(sequence[i]);
		}
		for (int i = 0; i < rs.size(); i++){
			if (rs[i] < sequence[end_cur])return false;
		}
		if ((!ls.empty()) && (!VerifySquenceOfBST(ls)))return false;
		if ((!rs.empty()) && (!VerifySquenceOfBST(rs)))return false;
		return true;
	}
};
class Solution1 {//效率较低的解法，对后序序列倒过来构建BST，再后序遍历构建出的BST看序列是否与输入序列相同
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())return false;
		TreeNode* root = new TreeNode(sequence[sequence.size() - 1]);
		for (int i = sequence.size() - 2; i >= 0; i--)
		{
			TreeNode*p = root;
			while (1)
			{
				if (sequence[i] > p->val){
					if (p->right == NULL){ p->right = new TreeNode(sequence[i]); break; }
					else { p = p->right; }
				}
				else{
					if (p->left == NULL){ p->left = new TreeNode(sequence[i]); break; }
					else { p = p->left; }
				}
			}
		} 
		vector<int> bcklist;
		back_tree(root, bcklist);
		for (int i=0; i < bcklist.size(); i++)
		{
			if (bcklist[i] != sequence[i])return false;
		}
		return root;
	}
	void back_tree(TreeNode* root, vector<int> &bck)
	{
		if (root == NULL)return;
		if (root->left != NULL)
		{
			back_tree(root->left, bck);
		}
		if (root->right != NULL)
		{
			back_tree(root->right, bck);
		}
		bck.push_back(root->val);
	}
};
//打印二叉树（广度优先）
void print_btree(TreeNode* root)
{
	queue<TreeNode*> node_q;
	node_q.push(root);
	while (!node_q.empty())
	{
		cout << node_q.front()->val << " ";
		if (node_q.front()->left != NULL)node_q.push(node_q.front()->left);
		if (node_q.front()->right != NULL)node_q.push(node_q.front()->right);
		node_q.pop();
	}
}
//打印二叉树（广度优先且隔层换行）
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
	TreeNode* m_tree = NULL;
	int  v1[] = { 5,7,6,9,11,10,8};
	vector<int> backv(&v1[0], &v1[sizeof(v1) / sizeof(int)]);

	Solution mys;
	cout << mys.VerifySquenceOfBST(backv) << endl;
	//print_btree2(m_tree);


	cout << "end" << endl;
	system("pause");
}