//s和p为空的判定，分3种情况
//当前匹配的是否为×，分2种情况
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        int ls=strlen(str),lp=strlen(pattern);
        if(!ls&&!lp)return true;
        if(!lp)return false;
        if(!ls&&(lp==1||pattern[1]!='*'))return false;
        if(lp==1||pattern[1]!='*')
        {
            if(pattern[0]!='.'&&pattern[0]!=str[0])
                return false;
            return match(str+1,pattern+1);
        }
        while(1)
        {    //当str为空时，可能无法通过if(match)返回结果，也有可能由于p[0]=.而无法跳出循环，所以要考虑str为空时的情况！！！
            if(!str[0])return match(str, pattern+2);
            if(match(str, pattern+2))
                return true;
            if(str[0]!=pattern[0]&&pattern[0]!='.')
                break;
            str++;
        }
        return false;
    }
};
