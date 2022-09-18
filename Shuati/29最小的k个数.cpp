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
