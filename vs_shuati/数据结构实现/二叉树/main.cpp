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
//�ؽ�������
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
//��ӡ��������������ȣ�
void BFS_Traverse(TreeNode* root)
{
	cout << "�������: ";
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
//��ӡ����������������Ҹ��㻻�У�
void BFS_Traverse_pro(TreeNode* root)
{
	queue<TreeNode*> node_q;
	node_q.push(root);
	TreeNode*rlast = root, *next_last = NULL;
	cout<<"��������Ҹ��㻻��: "<<endl ;
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
//�����������
//����ջ���ֽ�������ѹջ�ٽ�������ѹջ
void DepthFirstSearch(TreeNode *root)
{
	stack<TreeNode*> nodeStack;
	nodeStack.push(root);
	cout << "�ǵݹ��������: ";
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

/*ǰ�������ǰ��
*/
 void nonRecurPreTraverse(BinaryNode* root){//ǰ�����
	stack<BinaryNode*> stk;
	BinaryNode* currentNode;
	BinaryNode* tmp;
	currentNode = root;
	cout << "�ǵݹ�ǰ��: ";
	while (currentNode != NULL || !stk.empty())
	{
		while (currentNode != NULL)//һֱ��һ��������
		{
			cout << currentNode->val << " ";
			stk.push(currentNode);
			currentNode = currentNode->left;
		}

		if (!stk.empty())//�任����
		{
			tmp = stk.top();
			stk.pop();
			currentNode = tmp->right;
		}
	}
	cout << endl;
}
 void nonRecurInTraverse(BinaryNode* root){//�������
	 stack<BinaryNode*> stk;
	 BinaryNode* currentNode;
	 BinaryNode* tmp;
	 currentNode = root;
	 cout << "�ǵݹ�����: ";
	 while (currentNode != NULL || !stk.empty())
	 {
		 while (currentNode != NULL)//һֱ��һ��������
		 {	 
			 stk.push(currentNode);
			 currentNode = currentNode->left;
		 }

		 if (!stk.empty())//�任����
		 {
			 tmp = stk.top();
			 cout << tmp->val << " ";
			 stk.pop();
			 currentNode = tmp->right;
		 }
	 }
	 cout << endl;
 }
 void InTraverse(BinaryNode* root){//�������
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
	vector<int> pre(&v1[0], &v1[sizeof(v1) / sizeof(int)]), vin(&v2[0], &v2[sizeof(v2) / sizeof(int)]);//ʹ�������ʼ��vectorʱ��vector(start, end)ע��end�ĵ�ַ���������һ��Ԫ�صĺ�һ����ַ

	Solution mys;
	m_tree = mys.reConstructBinaryTree(pre, vin);
	BFS_Traverse(m_tree);
	BFS_Traverse_pro(m_tree); 
	DepthFirstSearch(m_tree);
	nonRecurPreTraverse(m_tree); 
	nonRecurInTraverse(m_tree);

	cout << "�������: ";
	DFS_Traverse(m_tree);
	cout << endl;

	cout << "�������: ";
	InTraverse(m_tree);
	cout << endl;


	cout << "end" << endl;
	system("pause");
}