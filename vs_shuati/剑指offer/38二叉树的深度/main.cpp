#include <iostream>
#include<algorithm>
using namespace std;

struct TreeNode{
	int val; 
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){
	}
};


class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)return 0;
		return 1+max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
	}
};


int main()
{
	cout << "end" << endl;
	system("pause");
}