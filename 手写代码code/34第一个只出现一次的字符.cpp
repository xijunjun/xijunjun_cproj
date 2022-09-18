class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty())return -1;
        vector<char>hash(256,0);
        for(int i=0;i<str.size();i++)
            hash[str[i]]=hash[str[i]]+1>2?2:hash[str[i]]+1;
        int i;
        for(i=0;i<str.size();i++)
            if(hash[str[i]]==1)break;
        return i;
    }
};
