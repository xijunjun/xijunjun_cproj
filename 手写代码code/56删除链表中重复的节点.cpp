//保留1个重复节点
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead)return NULL;
        ListNode*pre=pHead,*cur=pre->next;
        while(cur)
        {
            if(cur->val==pre->val)//当前节点的值等于前一个节点，那么删掉当前节点
                pre->next=cur->next;
            else 
                pre=pre->next;
            cur=cur->next;
        }
        return pHead;
    }
};
//核心思路：遍历链表，若当前节点既不等于前面节点也不等于后面节点，那么将该节点加入到去重后的链表中
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode*cur=pHead,*pre=NULL,*res=NULL,*prt=NULL;
        while(cur)
        {
            if((!pre||pre->val!=cur->val)&&(!cur->next||cur->val!=cur->next->val))
            {
                if(!res)
                    prt=res=cur;
                else{
                        res->next=cur;
                        res=res->next;
                    }
            }
            pre=cur;
            cur=cur->next;
        }
        if(prt)res->next=NULL;
        return prt;
    }
};
