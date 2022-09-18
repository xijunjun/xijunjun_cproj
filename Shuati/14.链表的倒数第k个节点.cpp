class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead)return NULL;
        ListNode *pres=pListHead;
        for(;k>=1;k--)
        {
            pListHead=pListHead->next;
            if(!pListHead)break;//没走完k步就到头了
        }
        if(k>1)return NULL;//
        while(pListHead)
        {
            pListHead=pListHead->next;
            pres=pres->next;
        }
        return pres;
    }
};  
