#include<iostream>
#include <stack>
#include<string>
#include<vector>
#include <algorithm>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
	char val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(char x) :
		val(x), left(NULL), right(NULL) {
	}
};
void RecurDe(TreeNode *plast,string str, int &st)
{
	
	if (st == str.size()-1)return;
	char val = '-';
	if (st == str.size() - 2)
		val = *str.rbegin();
	if (str[st] == '0')
	{
		if (!plast->left)plast->left = new TreeNode(val);
		RecurDe(plast->left,  str, ++st);
	}
	else 
	{
		if (!plast->right)plast->right = new TreeNode(val);
		RecurDe(plast->right, str, ++st);
	}
}
void decode_string(TreeNode*oritree,TreeNode *root, string s, int st, string &res)
{
	if (!root)return;
	if ( (!root->left&&!root->right))
	{
		res.push_back(root->val);
		root = oritree;
	}
	if (st == s.size())
		return;
	if (s[st] == '0')
		decode_string(oritree,root->left, s, st + 1, res);
	else 
		decode_string(oritree,root->right, s, st + 1, res);
}

int main()
{
	string stable[] = { "010a", "000b",  "1101c",  "1010d",  "1000e", "0111f" };
	int st = 0;
	TreeNode* root = new TreeNode('-');
	for (int i = 0; i < 6; i++){
		st = 0;
		RecurDe(root, stable[i],st);
	}
	string strcode = "10100100001101101010000111";
	string res = "";
	decode_string(root, root, strcode, 0, res);
	cout << res;

	system("pause");
}
