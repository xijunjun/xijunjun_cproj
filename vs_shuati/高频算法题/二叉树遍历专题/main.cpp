#include <iostream>
#include<string>
#include<stack>
#include<vector>
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
TreeNode* RecurDe(string &str, int &st)
{
	TreeNode *root = NULL;
	int ind = str.find_first_of(',', st);
	if (str[st] == '#') //最后调用的两个一定是两个#号，因为最后叶节点的两个子节点都为空，所以不需要考虑str的结束符，因为在这之前已经停止递归了 
		st = ind + 1;
	else {
		root = new TreeNode(stoi(str.substr(st, ind - st)));
		st = ind + 1;
		root->left = RecurDe(str, st);
		root->right = RecurDe(str, st);
	}
	return root;
}
TreeNode* Deserialize(char *str)
{
	int st = 0;
	if (str == NULL)return NULL;
	return RecurDe(string(str), st);
}
void recPreTra(TreeNode *root)
{
	if (!root)return;
	cout << root->val << ",";
	recPreTra(root->left);
	recPreTra(root->right);
}

vector<vector<int>>Row_Tra(TreeNode*root)
{
	vector<vector<int>>res;
	if (!root)return res;
	vector<int>tmp;
	TreeNode*pend=root;
	queue<TreeNode*>q;
	q.push(root);
	while (!q.empty())
	{

	}
}

int main()
{
//    1
//  2   3
// 4 5 6
	char *ptr = "1,2,4,#,#,5,#,#,3,#,6,#,#";
	TreeNode* tree=Deserialize(ptr);

	//recPreTraRec(tree);


	//string str = string(ptr);
	//cout << str.find_first_of(',', 0);
	//cout << 1+stoi(str.substr(0,2))<<endl;

	cout << "end" << endl;
	system("pause");
}