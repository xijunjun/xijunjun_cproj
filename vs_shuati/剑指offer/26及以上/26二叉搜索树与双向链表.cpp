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
/*
˼·��������������convertΪ˫���������Եݹ������ݹ��ϵ�������ʵ��ڵ�rootʱ��root->left��ת�����������������ɻ�ָ��
root->right��ת�����������������ɻ�ָ���������⣬���ֵΪ����ڵ㣬��root������������Ҳ���������������ָ�룬������
�������������ظ��ڵ�ָ�롣���ڷ��ص�ָ��������ģ���root->leftҪָ���������������ҵ�ָ�룬������������������ʱ��Ҫ������
��ָ���Ƶ����ҡ���root->right������������������ָ�룬��ֱ�����ӡ�
*/
class Solution {
public:
	TreeNode*  Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)return NULL;
		if (pRootOfTree->right != NULL){
			pRootOfTree->right = Convert(pRootOfTree->right);
			pRootOfTree->right->left = pRootOfTree;
		}
		if (pRootOfTree->left != NULL){
			TreeNode* pmin = Convert(pRootOfTree->left);
			TreeNode*pmax = pmin;
			while (pmax->right != NULL)pmax = pmax->right;
			pRootOfTree->left = pmax;
			pRootOfTree->left->right = pRootOfTree;
			return pmin;
		}
		return pRootOfTree;
	}
};

/*
�������˼·������ⷨ����
��������Խڵ�ķ���˳���ת������������ҵ�˳����һ���ġ��������������ʱ������������ڵ�Ļ�ָ���ɡ����������ǰ�ǰһ���ڵ��¼����Ȼ��pre->right = cur; cur->left = pre��
*/

class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr) return nullptr;
		TreeNode* pre = nullptr;
		convertHelper(pRootOfTree, pre);
		TreeNode* res = pRootOfTree;
		while (res->left)
			res = res->left;
		return res;
	}
	void convertHelper(TreeNode* cur, TreeNode*& pre)
	{
		if (cur == nullptr) return;
		convertHelper(cur->left, pre);
		cur->left = pre;
		if (pre) pre->right = cur;
		pre = cur;
		convertHelper(cur->right, pre);
	}
};