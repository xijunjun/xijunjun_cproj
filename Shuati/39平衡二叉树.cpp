class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return  -1!=Depth(pRoot);
    }
    int Depth(TreeNode*root)
    {
        if(!root)return 0;
        int ld=Depth(root->left);
        if(ld==-1)
            return -1;
        int rd=Depth(root->right);
        if(rd==-1||abs(ld-rd)>1)
            return -1;
        return 1+max(ld,rd);
    }
};
