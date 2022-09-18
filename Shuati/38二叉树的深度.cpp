class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot)return 0;
        return 1+max(TreeDepth(pRoot->left),TreeDepth(pRoot->right));
    }
};
