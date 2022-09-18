//1.若当前节点有右子树，访问其右子树第一个节点2.否则一直向上寻找，若当前节点是其父节点的左子树或者父节点为空便可返回父节点
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode)return NULL;
        if(!pNode->right){
            while(1)
            {
                if(!pNode->next||pNode->next->left==pNode)
                    return pNode->next;
                pNode=pNode->next;
            }
        }
        pNode=pNode->right;
        while(pNode->left)
            pNode=pNode->left;
        return pNode;
    }
};
