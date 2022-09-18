class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<10)return n>0;
        int w=10;
        while(n%w!=n)
          w*=10;
        w/=10;
        int g=n/w,d=n%w;
        return (g==1?d+1:w)+g*NumberOf1Between1AndN_Solution(w-1)+
               NumberOf1Between1AndN_Solution(d);
    }
};
//推荐写法，逐位计算
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int cnt=0;
        for(int w=1;w<=n;w*=10)
        {
            int g=n/w,d=n%w;
            cnt+=(g+8)/10*w+(g%10==1)*(d+1);
        }
        return cnt;
    }
};
