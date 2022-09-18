class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int>res;
        if(array.size()<2)return res;
        sort(array.begin(),array.end());
        int lind=0,rind=array.size()-1;
        while(1)
        {
            if(lind==rind)
                return res;
            if(array[lind]+array[rind]==sum)
                break;
            if(array[lind]+array[rind]>sum)
                rind--;
            else 
                lind++;
        }
        res.push_back(array[lind]);
        res.push_back(array[rind]);
        return res;
    }
};
