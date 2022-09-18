#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){
	}
};

//��ѽⷨ
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)return true;
		return isequal(pRoot->left, pRoot->right);
	}
	//�ж��������Ƿ����:p1->val==p2->val����p1������������p2������������p1������������p2��������
	//�ж��������Ƿ�Գ�:p1->val==p2->val����p1������������p2������������p1������������p2��������
	//�ܵ���˵���ǡ��ҵ����������ҡ�
	//��ָoffer���ͣ�isequalʵ���϶���p1�ǡ������ҡ������������������p2���ǡ������󡱵�������������ֽ����ƺ��������
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