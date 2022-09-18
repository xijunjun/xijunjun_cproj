class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode*cur,*plast=NULL,*pres=NULL,*root=pRootOfTree;
        stack<TreeNode*>sta;
        while(1)
        {
            while(root)
            {
                sta.push(root);
                root=root->left;
            }
            if(sta.empty())break;
            cur=sta.top();
            sta.pop();
            if(!pres)pres=cur;
            cur->left=plast;
            if(plast)plast->right=cur;
            root=cur->right;
            plast=cur;
        }
        return pres;
    }
};
