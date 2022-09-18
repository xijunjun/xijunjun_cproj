#include <iostream>
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
//两个栈（复杂版）
class Solution1 {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		queue<TreeNode*>q1, q2;
		q1.push(pRoot);
		TreeNode* cur = pRoot;
		vector<vector<int> > rtv;
		if (pRoot == NULL)return rtv;
		{
			vector<int> res;
			res.push_back(cur->val);
			rtv.push_back(res);
		}
		while (1)
		{
			{
				vector<int> res;
				while (1)
				{
					if (q1.empty())
					{
						if (res.size() == 0)
							return rtv;
						rtv.push_back(res);
						break;
					}
					cur = q1.front();
					q1.pop();
					if (cur->left != NULL)
					{
						q2.push(cur->left);
						res.push_back(cur->left->val);
					}
					if (cur->right != NULL)
					{
						q2.push(cur->right);
						res.push_back(cur->right->val);
					}
				}
			   }
				{
					vector<int> res;
					while (1)
					{
						if (q2.empty())
						{
							if (res.size() == 0)
								return rtv;
							rtv.push_back(res);
							break;
						}
						cur = q2.front();
						q2.pop();
						if (cur->left != NULL)
						{
							q1.push(cur->left);
							res.push_back(cur->left->val);
						}
						if (cur->right != NULL)
						{
							q1.push(cur->right);
							res.push_back(cur->right->val);
						}
					}
				}
			
		}
	}
};
//两个栈简洁版
class Solution2 {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		queue<TreeNode*>q1, q2;
		q1.push(pRoot);
		TreeNode* cur = pRoot;
		vector<vector<int> > rtv;
		if (pRoot == NULL)return rtv;
		rtv.push_back(vector<int>(&cur->val, &cur->val + 1));
		queue<TreeNode*>*p1 = &q1, *p2 = &q2;
		while (1)
		{
			vector<int> res;
			while (1)
			{
				if (p1->empty())
				{
					if (res.size() == 0)
						return rtv;
					rtv.push_back(res);
					break;
				}
				cur = p1->front();
				p1->pop();
				if (cur->left){
					p2->push(cur->left);
					res.push_back(cur->left->val);
				}
				if (cur->right){
					p2->push(cur->right);
					res.push_back(cur->right->val);
				}
			}
			swap(p1, p2);
		}
	}
};
//按行打印，需要知道什么时候到达每一行的末尾，用一个last来记录末尾，可以初始化为pRoot，但问题是什么时候更新last呢？
//上一行刚访问完将下一行所有节点刚压入队列时，队尾最新插入的节点也就是新的last。所以用nextlast来实时记录队尾的节点，一旦上一行访问到last，则令last=nextlast。
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		TreeNode*last = pRoot, *nextlast, *cur;
		queue<TreeNode*>q;
		q.push(pRoot);
		vector<int>res;
		vector<vector<int> > rtval;
		if (!pRoot)return rtval;
		while (1)
		{
			if (q.empty())
				return rtval;
			cur = q.front();
			q.pop();
			res.push_back(cur->val);
			if (cur->left)
				q.push(nextlast = cur->left);
			if (cur->right)
				q.push(nextlast = cur->right);
			if (cur == last){
				last = nextlast;
				rtval.push_back(res);
				res.clear();
			}
		}

	}
};
int main()
{
	cout << "end" << endl;
	system("pause");
}