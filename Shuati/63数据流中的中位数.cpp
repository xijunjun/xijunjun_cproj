//使用STl中的priority_queue
class Solution {
public:
    priority_queue<int ,vector<int>,less<int>>q1;
    priority_queue<int ,vector<int>,greater<int>>q2;
    void Insert(int num)
    {
        if(q1.empty()||num<q1.top())
            q1.push(num);
        else 
            q2.push(num);
        if(q1.size()<q2.size()){
            q1.push(q2.top());
            q2.pop();
        }
        if(q1.size()>q2.size()+1){
            q2.push(q1.top());
            q1.pop();
        }
    }

    double GetMedian()
    { 
        if(q1.empty())return 0;
        return q1.size()==q2.size()?(q1.top()+q2.top())*0.5:q1.top();
    }
};
//用vector实现堆，并实现priority_queue的pop和push操作即可
class Solution {
public:
    vector<int>q1,q2;
    void push(vector<int>&a,int num,bool ismin)
    {
        a.push_back(num);
        int ind=a.size()-1,nextind;
        while(1)
        {
            if(ind==0)break;
            nextind=(ind-1)/2;
            if((a[ind]>a[nextind])^ismin)
                swap(a[ind],a[nextind]);
            else break;
            ind=nextind;
        }
    }
    void pop(vector<int>&a,bool ismin)
    {
        swap(a[0],*a.rbegin());
        a.pop_back();
        int ind=0,nextind,len=a.size();
        while(1)
        {
            nextind=ind*2+1;
            if(nextind>=len)break;
            if(nextind+1<len&&(ismin^(a[nextind+1]>a[nextind])))
                nextind++;
            if((ismin^(a[nextind]>a[ind])))
                swap(a[nextind],a[ind]);
            else break;
            ind =nextind;
        }
    }
    void Insert(int num)
    {
        if(q1.empty()||q1[0]>num)
            push(q1,num,false);
        else push(q2,num,true);
        if(q1.size()>q2.size()+1){
            push(q2,q1[0],true);
            pop(q1,false);
        }
        if(q2.size()>q1.size()){
            push(q1,q2[0],false);
            pop(q2,true);
        }  
    }
    double GetMedian()
    { 
        if(q1.empty())return 0;
        return q1.size()==q2.size()?(q1[0]+q2[0])*0.5:q1[0];
    }
};
// 使用replace_top
class Solution {
public:
    vector<int>q1,q2;
    void push(vector<int>&a,int num,bool ismin)
    {
        a.push_back(num);
        int ind=a.size()-1,nextind;
        while(1)
        {
            if(ind==0)break;
            nextind=(ind-1)/2;
            if((a[ind]>a[nextind])^ismin)
                swap(a[ind],a[nextind]);
            else break;
            ind=nextind;
        }
    }
    void replace_top(vector<int>&a,int num,bool ismin)
    {
        a[0]=num;
        int ind=0,nextind,len=a.size();
        while(1)
        {
            nextind=ind*2+1;
            if(nextind>=len)break;
            if(nextind+1<len&&(ismin^(a[nextind+1]>a[nextind])))
                nextind++;
            if((ismin^(a[nextind]>a[ind])))
                swap(a[nextind],a[ind]);
            else break;
            ind =nextind;
        }
    }
    void Insert(int num)
    {
        if(q1.empty()||num<=q1[0])
        {
            if(q1.size()==q2.size())
                push(q1,num,false);
            else{
                push(q2,q1[0],true);
                replace_top(q1,num,false);
            }   
        }
        else{
            if(q1.size()==q2.size()+1)
                push(q2,num,true);
            else{
                push(q1,min(q2[0],num),false);
                replace_top(q2,max(q2[0],num),true);
            } 
        }
    }
    double GetMedian()
    { 
        if(q1.empty())return 0;
        return q1.size()==q2.size()?(q1[0]+q2[0])*0.5:q1[0];
    }
};
