class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int>dq;
        for(int i=0;i<num.size();i++)
        {
            if(!dq.empty()&&i-dq.front()>size-1)
                dq.pop_front();
            while(1){
                 if(dq.empty()||num[i]<num[dq.back()])
                {
                    dq.push_back(i);
                    break;
                }
                else dq.pop_back();
            } 
            if(i>=size-1)res.push_back(num[dq.front()]);
        }
        return res;
    }
};
