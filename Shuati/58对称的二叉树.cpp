class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot)return true;
        return isequal(pRoot->left,pRoot->right);
    }
    bool isequal(TreeNode*root1,TreeNode *root2)
    {
        if(!root1&&!root2)return true;
        if(!root1||!root2)return false;
        return root1->val==root2->val&&isequal(root1->left,root2->right)&&isequal(root2->left,root1->right);
    }
};
