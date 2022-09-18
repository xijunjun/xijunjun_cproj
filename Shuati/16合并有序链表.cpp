//递归解法
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *p;
        if(!pHead1)return pHead2;
        if(!pHead2)return pHead1;
        if(pHead1->val>pHead2->val)
            swap(pHead1,pHead2);
        p=pHead1;
        pHead1=pHead1->next;
        p->next=Merge(pHead1,pHead2);
        return p;
    }
};
//普通解法，新建一个头，选小的添加
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *p,*pres;
        if(!pHead1)return pHead2;
        if(!pHead2)return pHead1;
        if(pHead1->val<pHead2->val){
            p=pHead1;
            pHead1=pHead1->next;
        }
        else {
            p=pHead2;
            pHead2=pHead2->next;
        }
        pres=p;
        while(1)
        {
            if(!pHead1)
            {
                p->next=pHead2;
                break;
            }
            if(!pHead2)
            {
                p->next=pHead1;
                break;
            }
            if(pHead1->val<pHead2->val)
            {
                p->next=pHead1;
                pHead1=pHead1->next;
            }
            else{
                p->next=pHead2;
                pHead2=pHead2->next;
            }
            p=p->next;
        }
        return pres;
    }
};
