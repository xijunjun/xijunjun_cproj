class Solution {
public:
        //弹出节点时将其子节点入队，若当前节点是行末节点，那么下一行的行末节点就是队列中最新的节点
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>>res;
            if(!pRoot)return res;
            TreeNode* cur,*end=pRoot;
            queue<TreeNode*>q;
            q.push(pRoot);
            vector<int>tmp;
            while(!q.empty())
            {
                cur=q.front();
                q.pop();
                tmp.push_back(cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
                if(cur==end)
                {
                    res.push_back(tmp);
                    tmp.clear();
                    if(!q.empty())end=q.back();
                }   
            }
            return res;
        }
};
