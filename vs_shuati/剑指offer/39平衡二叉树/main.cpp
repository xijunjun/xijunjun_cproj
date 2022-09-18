#include <iostream>
#include<algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode*left, *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){
	}
};

//简单解法，有大量重复计算
class Solution2 {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL)return 1;
		return (IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right)&&abs(getDepth(pRoot->left) - getDepth(pRoot->right)) <= 1  );
	}
	int getDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)return 0;
		return 1 + max(getDepth(pRoot->left), getDepth(pRoot->right));
	}
};
//在递归求深度时进行判断
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL)return 1;
		return getDepth(pRoot) != -1;
	}
	int getDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)return 0;
		int llenth = getDepth(pRoot->left);
		if (llenth == -1)return -1;
		int rlenth = getDepth(pRoot->right);
		if (rlenth == -1)return -1;
		if (abs(llenth - rlenth) > 1)
			return -1;
		else 
			return 1 + max(llenth,rlenth);
	}
};


int main()
{

	double jj = 0;
	jj++;
	cout << jj << endl;
	cout << "end" << endl;
	system("pause");
}