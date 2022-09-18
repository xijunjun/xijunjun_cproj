class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int fn=array[0],res=array[0];
        for(int i=1;i<array.size();i++)
        {
            fn=fn>0?fn+array[i]:array[i];
            if(fn>res)res=fn;
        }
        return res;
    }
};
