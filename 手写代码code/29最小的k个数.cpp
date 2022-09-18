//partition解法
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>res;
        if(input.empty()||input.size()<k||k==0)
            return res;
        int st=0,ed=input.size()-1;
        while(1)
        {
            int p=partition(input,st,ed);
            if(p==k-1)break;
            if(p>k-1)ed=p-1;
            else st=p+1;
        }
        return vector<int>(input.begin(),input.begin()+k);
    }
    int partition(vector<int>&a,int st,int ed)
    {
        if(st==ed)return st;
        int insert_index=st;
        for(int i=st;i<ed;i++)
            if(a[i]<=a[ed])
                swap(a[i],a[insert_index++]);
        swap(a[ed],a[insert_index]);
        return insert_index;
    }
};
//大顶堆解法
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        if(k>len)return vector<int>();
        for(int i=k/2-1;i>=0;i--)
            heap_adj(input,i,k-1);
        for(int i=k;i<len;i++)
        {
            if(input[0]>input[i])
            {
                swap(input[0],input[i]);
                heap_adj(input,0,k-1);
            }
        }
        return vector<int>(input.begin(),input.begin()+k);
    }
    void heap_adj(vector<int>&a,int st,int ed)
    {
        int ind=st,nextind;
        while(1)
        {
            nextind=ind*2+1;
            if(nextind>ed)break;
            if(nextind+1<=ed&&a[nextind+1]>a[nextind])
                nextind++;
            if(a[nextind]>a[ind])
                swap(a[nextind],a[ind]);
            else 
                break;
            ind=nextind;
        }
    }
};
