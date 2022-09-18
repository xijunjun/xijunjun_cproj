#include <iostream>
#include<vector>
#include<stack>
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
//����˼·������ջ
//��ӡ˳���ͨ����������һ�е�˳���Ƿ���
//��ͬ����ͨ���е�д���ǵ�����ʱ���ӡ���˴���ѹ���ʱ���ӡ
//���ڶ�������ĳһ�У��������Ǵ������ҵش�ӡ���У�����ͨ����һ�д�ӡ��һ��ʱȴ��Ҫ����ط��ʸ��У���ջ���þ��з���Ĺ��ܡ�
//���Ƚ����ڵ㣨�������ң�ѹ��sta1����ͨ������sta1��ӡ�ڶ���ʱ��������ش�ӡ��ͬʱ��Ԫ��ѹ��һ��ջsta2����ŷ���sta2��
//��ͨ��sta2�������Ҵ�ӡ��һ�У�ͬʱѹ��sta1����������ջ�������б������֮�δ�ӡ��
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>>rtv;
		if (pRoot == NULL)return rtv;
		stack<TreeNode*>sta1, sta2;
		sta1.push(pRoot);
		TreeNode* cur = NULL;
		bool isr = 1;
		{
			vector<int> res;
			res.push_back(pRoot->val);
			rtv.push_back(res);
		}
		while (1)
		{
			{
				vector<int> res;
				while (1)
				{
					if (sta1.size() == 0)
					{
						if (res.size() == 0)
							return rtv;
						rtv.push_back(res);
						break;
					}
					cur = sta1.top();
					sta1.pop();
					if (cur->right != NULL){
						res.push_back(cur->right->val);
						sta2.push(cur->right);
					}
					if (cur->left != NULL){
						res.push_back(cur->left->val);
						sta2.push(cur->left);

					}

				}
			}
			{
			vector<int> res;
			while (1)
			{
				if (sta2.size() == 0)
				{
					if (res.size() == 0)
						return rtv;
					rtv.push_back(res);
					break;
				}
				cur = sta2.top();
				sta2.pop();
				if (cur->left != NULL){
					res.push_back(cur->left->val);
					sta1.push(cur->left);
				}
				if (cur->right != NULL){
					res.push_back(cur->right->val);
					sta1.push(cur->right);
				}
			}
		}
		}
	}
};
int main()
{
	cout << "end" << endl;
	system("pause");
}