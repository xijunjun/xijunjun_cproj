#include <iostream>
#include <vector>
#include<queue>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
typedef TreeNode BinaryNode;
//重建二叉树
class Solution {
public:
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
};
//打印二叉树（广度优先）
void BFS_Traverse(TreeNode* root)
{
	cout << "广度优先: ";
	queue<TreeNode*> node_q;
	node_q.push(root);
	while (!node_q.empty())
	{
		cout << node_q.front()->val << " ";
		if (node_q.front()->left != NULL)node_q.push(node_q.front()->left);
		if (node_q.front()->right != NULL)node_q.push(node_q.front()->right);
		node_q.pop();
	}
	cout << endl;
}
//打印二叉树（广度优先且隔层换行）
void BFS_Traverse_pro(TreeNode* root)
{
	queue<TreeNode*> node_q;
	node_q.push(root);
	TreeNode*rlast = root, *next_last = NULL;
	cout<<"广度优先且隔层换行: "<<endl ;
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
void DFS_Traverse(TreeNode* root)
{
	
	if (root == NULL)return;
	cout <<root->val << " ";
	DFS_Traverse(root->left);
	DFS_Traverse(root->right);
}
//深度优先搜索
//利用栈，现将右子树压栈再将左子树压栈
void DepthFirstSearch(TreeNode *root)
{
	stack<TreeNode*> nodeStack;
	nodeStack.push(root);
	cout << "非递归深度优先: ";
	while (!nodeStack.empty())
	{
		TreeNode *node = nodeStack.top();
		cout << node->val << ' ';
		nodeStack.pop();
		if (node->right)
		{
			nodeStack.push(node->right);
		}
		if (node->left)
		{
			nodeStack.push(node->left);
		}
	}
	cout << endl;
}

/*前序遍历，前序
*/
 void nonRecurPreTraverse(BinaryNode* root){//前序遍历
	stack<BinaryNode*> stk;
	BinaryNode* currentNode;
	BinaryNode* tmp;
	currentNode = root;
	cout << "非递归前序: ";
	while (currentNode != NULL || !stk.empty())
	{
		while (currentNode != NULL)//一直往一个方向走
		{
			cout << currentNode->val << " ";
			stk.push(currentNode);
			currentNode = currentNode->left;
		}

		if (!stk.empty())//变换方向
		{
			tmp = stk.top();
			stk.pop();
			currentNode = tmp->right;
		}
	}
	cout << endl;
}
 void nonRecurInTraverse(BinaryNode* root){//中序遍历
	 stack<BinaryNode*> stk;
	 BinaryNode* currentNode;
	 BinaryNode* tmp;
	 currentNode = root;
	 cout << "非递归中序: ";
	 while (currentNode != NULL || !stk.empty())
	 {
		 while (currentNode != NULL)//一直往一个方向走
		 {	 
			 stk.push(currentNode);
			 currentNode = currentNode->left;
		 }

		 if (!stk.empty())//变换方向
		 {
			 tmp = stk.top();
			 cout << tmp->val << " ";
			 stk.pop();
			 currentNode = tmp->right;
		 }
	 }
	 cout << endl;
 }
 void InTraverse(BinaryNode* root){//后序遍历
	 if (root == NULL)return;
	 InTraverse(root->left);
	 InTraverse(root->right);
	 cout << root->val << " ";
 }
int main()
{
	/*
	       6
		  / \
	     8   3
	    / \
	   9   2
	      / \
	     4   7
		 */
	TreeNode* m_tree = NULL;
	int  v1[] = { 6, 8, 9, 2, 4, 7, 3 };
	int  v2[] = { 9, 8, 4, 2, 7, 6, 3 };
	vector<int> pre(&v1[0], &v1[sizeof(v1) / sizeof(int)]), vin(&v2[0], &v2[sizeof(v2) / sizeof(int)]);//使用数组初始化vector时，vector(start, end)注意end的地址是数组最后一个元素的后一个地址

	Solution mys;
	m_tree = mys.reConstructBinaryTree(pre, vin);
	BFS_Traverse(m_tree);
	BFS_Traverse_pro(m_tree); 
	DepthFirstSearch(m_tree);
	nonRecurPreTraverse(m_tree); 
	nonRecurInTraverse(m_tree);

	cout << "深度优先: ";
	DFS_Traverse(m_tree);
	cout << endl;

	cout << "后序遍历: ";
	InTraverse(m_tree);
	cout << endl;


	cout << "end" << endl;
	system("pause");
}