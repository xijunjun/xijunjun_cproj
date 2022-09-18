//记非环节点长度为a，那么从pHead走a+1步到达环首
//ListNode* pfast=pHead->next->next,*pslow=pHead->next;
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead||!pHead->next)return NULL;
        ListNode* pfast=pHead->next->next,*pslow=pHead->next;
        while(1)//相当于忽略了pHead，所以在计算非环长度时不把pHead计入非环部分长度
        {
            if(!pfast||!pfast->next)return NULL;
            if(pfast==pslow)
                break;
            pfast=pfast->next->next;
            pslow=pslow->next;
        }
        pfast=pHead;//由于前面忽略了pHead的长度，所以从pHead开始走直到相遇正好走非环的长度+1步
        while(1)
        {
            if(pslow==pfast)break;
            pslow=pslow->next;
            pfast=pfast->next;
        }
        return pslow;
    }
};
//ListNode* pfast=pHead->next,*pslow=pHead;
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead||!pHead->next)return NULL;
        ListNode* pfast=pHead->next,*pslow=pHead;
        while(1)
        {
            if(!pfast||!pfast->next)return NULL;
            if(pfast==pslow)
                break;
            pfast=pfast->next->next;
            pslow=pslow->next;
        }
        pfast=pHead;
        pslow=pslow->next;//要让pslow在环中继续走非环的长度+1步
        while(1)
        {
            if(pslow==pfast)break;
            pslow=pslow->next;
            pfast=pfast->next;
        }
        return pslow;
    }
};
