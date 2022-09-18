class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        int lind=LowerBound(data,k);
        if(lind==-1||data[lind]!=k)
            return 0;
        int rind=UpperBound(data,k);
        if(rind==0||data[rind-1]!=k)
            return 0;
        return rind-lind;
    }
    int LowerBound(vector<int>&a,int k)
    {
        int st=0,ed=a.size()-1,mid;
        while(1)
        {
            if(st>ed)return -1;
            mid=(st+ed)/2;
            if(a[mid]>=k&&(mid==0||a[mid-1]<k))
                return mid;
            if(a[mid]>=k)
                ed=mid-1;
            else 
                st=mid+1;
        }
    }
    int UpperBound(vector<int>&a,int k)
    {
        int st=0,ed=a.size()-1,mid;
        while(1)
        {
            if(st>ed)return a.size();
            mid=(st+ed)/2;
            if(a[mid]>k&&(mid==0||a[mid-1]<=k))
                return mid;
            if(a[mid]>k)
                ed=mid-1;
            else 
                st=mid+1;
        }
    }
};
