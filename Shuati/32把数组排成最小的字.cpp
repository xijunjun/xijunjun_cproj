//重新定义比较大小的方式
class Solution {
public:
    static bool cmp(int a,int b)
    {
        return to_string(a)+to_string(b)<to_string(b)+to_string(a);
    }
    string PrintMinNumber(vector<int> numbers) {
        string res="";
        sort(numbers.begin(),numbers.end(),cmp);
        for(auto it=numbers.begin();it!=numbers.end();it++)
            res+=to_string(*it);
        return res;
    }
};
