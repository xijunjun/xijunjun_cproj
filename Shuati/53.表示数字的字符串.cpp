class Solution {
public:
    bool isnum(char* s)
    {
        if(!s)return false;
        int len=strlen(s);
        int signflag=0,dotflag=0,numflag=0;
        if(s[0]=='+'||s[0]=='-')
            signflag=1;
        for(int i=signflag;i<len;i++)
        {
            if(dotflag==0&&s[i]=='.')
                dotflag=1;
            else if(s[i]>'9'||s[i]<'0')
                return false;
            numflag=1;
        }
        return numflag;
    }
    bool isNumeric(char* string)
    {
        int len=strlen(string);
        if(!len)return false;
        int ind=strcspn(string,"eE");
        if(ind==len)
            return isnum(string);
        if(strchr(string+ind+1,'.'))return false;
        string[ind]=0;
        return isnum(string)&&isnum(string+ind+1);
    }
};
