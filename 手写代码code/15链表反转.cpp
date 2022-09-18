class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
         ListNode* plast=NULL,*pcur=pHead,*ptemp;
        while(1)
        {
            if(!pcur)break;
            ptemp=pcur->next;
            pcur->next=plast;
            plast=pcur;
            pcur=ptemp;
        }
        return plast;
    }
};
