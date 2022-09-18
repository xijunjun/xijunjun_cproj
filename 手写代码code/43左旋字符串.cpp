class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.empty())return str;
        return (str+str).substr(n%str.size(),str.size());
    }
};
