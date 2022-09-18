//递归
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>res;
        recPrint(head,res);
        return res;
    }
    void recPrint(ListNode*head,vector<int>&a)
    {
        if(!head)return ;
        if(head->next)
            recPrint(head->next,a);
        a.push_back(head->val);
    }
};
//非递归（更好的解法）
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>res;
        while(head)
        {
            res.push_back(head->val);
            head=head->next;
        }
        int lenth=res.size();
        for(int i=0;i<=lenth/2-1;i++)
        {
            swap(res[i],res[lenth-1-i]);
        }
        return res;
    }
};
