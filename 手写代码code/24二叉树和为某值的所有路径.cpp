class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        stack<TreeNode*>sta;
        vector<vector<int>>res;
        vector<int>curpath;
        int sum=0;
        TreeNode*cur,*plast=root;
        while(1)
        {
            while(root)
            {
                sta.push(root);
                curpath.push_back(root->val);
                sum+=root->val;
                root=root->left;
            }
            if(sta.empty())break;
            cur=sta.top();
            if((!cur->left&&!cur->right)||(!cur->right&&cur->left==plast)||cur->right==plast)
            {
               if(sum==expectNumber&&(!cur->left&&!cur->right))res.push_back(curpath);   
               sum-=cur->val;
               root=NULL;
               sta.pop();
               curpath.pop_back();
               plast=cur;
            }
            else root=cur->right;
        }
        return res;
    }
};
