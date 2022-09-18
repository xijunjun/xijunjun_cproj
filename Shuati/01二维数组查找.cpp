class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()||array[0].empty())return false;
        int j=0,i=array[0].size()-1;
        while(1)
        {
            if(array[j][i]==target)
                return true;
            if(array[j][i]>=target)
                i--;
            else j++;
            if(i<0||j>=array.size())
                break;
        }
        return false;
    }
};
