class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>>res;
        if(!pRoot)return res;
        stack<TreeNode*>sta1,sta2;
        sta1.push(pRoot);
        res.push_back(vector<int>(1,pRoot->val));
        vector<int>tmp;
        TreeNode*cur;
        while(1)
        {
            while(!sta1.empty())
            {
                cur=sta1.top();
                if(cur->right){
                    sta2.push(cur->right);
                    tmp.push_back(cur->right->val);
                }
                if(cur->left){
                    sta2.push(cur->left);
                    tmp.push_back(cur->left->val);
                }
                sta1.pop();
            }
            if(!tmp.empty())res.push_back(tmp);
            tmp.clear();
            if(sta2.empty())break;
            while(!sta2.empty())
            {
                cur=sta2.top();
                if(cur->left){
                    sta1.push(cur->left);
                    tmp.push_back(cur->left->val);
                }
                if(cur->right){
                    sta1.push(cur->right);
                    tmp.push_back(cur->right->val);
                }
                sta2.pop();
            }
            if(!tmp.empty())res.push_back(tmp);
            tmp.clear();
            if(sta1.empty())break;
        }
        return res;
    }
    
};
