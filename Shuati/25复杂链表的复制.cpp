class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)return NULL;
        RandomListNode*p=pHead,*tmp,*pres;
        while(p){
            tmp=p->next;
            p->next=new RandomListNode(p->label);
            p->next->next=tmp;
            p=tmp;
        }
        p=pHead;
        while(p){
            if(p->random)p->next->random=p->random->next;
            p=p->next->next;
        }
        p=pHead;
        pres=p->next;
        while(p->next){   
            tmp=p->next;
            p->next=p->next->next;
            p=tmp;
        }
        return pres;
    }
};
