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
//核心思路：两个栈
//打印顺序和通过它访问下一行的顺序是反的
//不同于普通队列的写法是弹出的时候打印，此处是压入的时候打印
//对于二叉树的某一行，假设我们从左往右地打印该行，但是通过这一行打印下一行时却需要反向地访问该行，而栈正好具有反向的功能。
//首先将根节点（从左往右）压入sta1，再通过弹出sta1打印第二行时从右往左地打印，同时把元素压到一个栈sta2里，接着访问sta2，
//再通过sta2从左往右打印下一行，同时压入sta1。这样两个栈交替运行便完成了之形打印。
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