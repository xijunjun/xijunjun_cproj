class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(k<1)return NULL;
        stack<TreeNode*>sta;
        int cnt=0;
        TreeNode* cur;
        while(1)
        {
            while(pRoot)
            {
                sta.push(pRoot);
                pRoot=pRoot->left;
            }
            if(sta.empty())break;
            cnt++;
            cur=sta.top();
            if(cnt==k)return cur;
            pRoot=cur->right;
            sta.pop();
        }
        return NULL;
    }
};
