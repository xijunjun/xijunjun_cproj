class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.empty())return 0;
        int cnt=0;
        vector<int>tmp(data);
        merge_cnt(data,tmp,0,data.size()-1,cnt);
        return cnt;
    }
    void merge_cnt(vector<int>&a,vector<int>&tmp,int st,int ed,int &cnt)
    {
        if(st==ed)return;
        int mid=(st+ed)/2;
        merge_cnt(a,tmp,st,mid,cnt);
        merge_cnt(a,tmp,mid+1,ed,cnt);
        for(int i=st;i<=ed;i++)
            tmp[i]=a[i];
        int lind=st,rind=mid+1;
        for(int i=st;i<=ed;i++)
        {
            if(lind>mid)
                a[i]=tmp[rind++];
            else if(rind>ed)
                a[i]=tmp[lind++];
            else if(tmp[rind]<tmp[lind])
            {
                cnt+=mid-lind+1;
                cnt%=1000000007;
                a[i]=tmp[rind++];
            }
            else 
                a[i]=tmp[lind++];
        }
    }
};
