class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty())return false;
        sort(numbers.begin(),numbers.end());
        int cnt=0;
        for(int i=0;i<numbers.size()-1;i++)
        {
            if(numbers[i]==0)
                cnt++;
            else if(numbers[i]==numbers[i+1])
                return false;
            else{
                cnt-=numbers[i+1]-numbers[i]-1;
                if(cnt<0)return false;
            }
        }
        return true;
    }
};
