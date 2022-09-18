class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1||!pHead2)return NULL;
        int l1=0,l2=0;
        ListNode *p1=pHead1,*p2=pHead2;
        while(p1){
            l1++;
            p1=p1->next;
        }
        while(p2){
            l2++;
            p2=p2->next;
        }
        p1=pHead1;
        p2=pHead2;
        if(l1<l2)
            swap(p1,p2);
        int k=abs(l1-l2);
        while(k-->0)
            p1=p1->next;
        while(p1)
        {
            if(p1==p2)break;
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};
