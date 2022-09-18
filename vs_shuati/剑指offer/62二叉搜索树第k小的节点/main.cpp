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


//����򵥵ĵݹ���������������м������������
//һ���ҵ���ֹͣ�ݹ����
class Solution1 {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		int cnt = 0;
		TreeNode* rtv = NULL;
		recfuc(pRoot, rtv, k, cnt);
		return rtv;
	}
	void recfuc(TreeNode* pRoot, TreeNode*& rtv, int  k, int &cnt)
	{
		if (pRoot == NULL)//�սڵ��򲻸ı�
			return;
		recfuc(pRoot->left, rtv, k, cnt);
		if (++cnt == k){//һ�����ʵ���kС�Ľڵ��򣬼�¼������ͨ��return��ֹͣ�ݹ鵽������
			rtv = pRoot;
			return;
		}
		recfuc(pRoot->right, rtv, k, cnt);
	}
};
class Solution2 {
public:
	int cnt = 0;
	//����ֻ��Ҫ�ҳ���k�������������Ҫ���������Խڵ㣬���Զ�����һ�ڵ���˵����������ȥ�жϣ�һ���ҵ��Ϳ���ֹͣ�ݹ飬ֹͣѹջ��
	//�ȸ�����ͨ�ĵݹ�д���������壬��������ֵ�ĺ�������pRoot�����ҵ���k�ڵ㡣
	//����ÿ�εݹ���þ��ж����������Ƿ����ҵ�k�ڵ㣬���ҵ��ˣ���ô�Ͳ����ټ����ݹ���ã�ֱ�ӷ������������ҵ��ļ��ɣ����û�ҵ������ǵü����ݹ�ذ��ո�->�ҵ�˳���ҡ�
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL)return NULL;
		TreeNode* node;
		node = KthNode(pRoot->left, k);
		if (node)return node;
		if (++cnt == k)return pRoot;
		node = KthNode(pRoot->right, k);
		if (node)return node;
		return NULL;
	}
};
//��node���ҵ��˾Ͳ���Ҫ���ң��ٵݹ飩��
class Solution3 {
public:
	int cnt = 0;
	TreeNode* node = NULL;
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL)return node;
		KthNode(pRoot->left, k);
		if (node)return node;
		if (++cnt == k)return node = pRoot;
		KthNode(pRoot->right, k);
		return node;
	}
};
int main()
{
	cout << "end" << endl;
	system("pause");
}