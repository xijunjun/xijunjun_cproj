class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())return 0;
        int st=0,w=1,res=0;
        if(str[0]=='+')
            st=1;
        if(str[0]=='-'){
            st=1;
            w=-1;
        }
        for(int i=str.size()-1;i>=st;i--)
        {
            if(str[i]>='0'&&str[i]<='9')
            {
                res+=w*(str[i]-'0');
                w*=10;
            }
            else return 0;
        }
        return res;
    }
};
