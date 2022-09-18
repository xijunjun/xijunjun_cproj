class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty())return str;
        reverse(str,0,str.size()-1);
        int st=-1;
        for(int i=0;i<str.size();i++)
        {
            if(st==-1&&str[i]!=' ')
                st=i;
            if(st!=-1&&(i==str.size()-1||str[i+1]==' '))
            {
                reverse(str,st,i);
                st=-1;
            } 
        }
        return str;
    }
    void reverse(string &s,int st,int ed)
    {
        while(st<=ed)
            swap(s[st++],s[ed--]);
    }
};
