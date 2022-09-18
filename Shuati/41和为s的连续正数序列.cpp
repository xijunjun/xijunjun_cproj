class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>>res;
        if(sum<2)return res;
        int ub=sqrt(2*sum);
        for(int n=ub;n>=2;n--)
        {
            int fzi=2*sum-n*n+n,a=fzi/2/n;
            if(fzi<=0||fzi!=a*2*n)
                continue;
            vector <int>tmp;
            for(int i=0;i<n;i++)
                tmp.push_back(a+i);
            res.push_back(tmp);
        }
        return res;
    }
};
