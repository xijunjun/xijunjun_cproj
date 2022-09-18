//递归遍历
class Solution {
public:
    bool isequal(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot2)return true;
        if(!pRoot1||pRoot1->val!=pRoot2->val)return false;
        return isequal(pRoot1->left,pRoot2->left)&&isequal(pRoot1->right,pRoot2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1||!pRoot2)return false;
        return isequal(pRoot1,pRoot2)||HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
    }
};
