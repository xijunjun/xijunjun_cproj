class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()||vin.empty())
            return NULL;
        return RecFunc(pre,0,pre.size()-1,vin,0,pre.size()-1);
    }
    TreeNode* RecFunc(vector<int>&pre,int st1,int ed1,vector<int>&in,int st2,int ed2)
    {
        TreeNode *root=new TreeNode(pre[st1]);
        int ind=st2;
        for(int i=st2;i<=ed2;i++){
            if(pre[st1]==in[i]){
                ind=i;
                break;
            }
        }
        if(ind>st2)
            root->left=RecFunc(pre,st1+1,st1+ind-st2,in,st2,ind-1);
        if(ind<ed2)
            root->right=RecFunc(pre,ed1-(ed2-ind-1),ed1,in,ind+1,ed2); 
        return root;
    }
};
//使用stl查找
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()||vin.empty())
            return NULL;
        return RecFunc(pre,0,pre.size()-1,vin,0,pre.size()-1);
    }
    TreeNode* RecFunc(vector<int>&pre,int st1,int ed1,vector<int>&in,int st2,int ed2)
    {
        TreeNode *root=new TreeNode(pre[st1]);
        int ind=find(in.begin()+st2,in.begin()+ed2+1,pre[st1])-in.begin();//注意in.begin()+ed2+1的加1，迭代器的最后一个是不访问的
        if(ind>st2)
            root->left=RecFunc(pre,st1+1,st1+ind-st2,in,st2,ind-1);
        if(ind<ed2)
            root->right=RecFunc(pre,ed1-(ed2-ind-1),ed1,in,ind+1,ed2); 
        return root;
    }
};
