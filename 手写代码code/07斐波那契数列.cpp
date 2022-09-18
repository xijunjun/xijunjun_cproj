class Solution {
public:
    int Fibonacci(int n) {
        if(n<=1)return n;
        int fn_1=1,fn_2=0,fn;
        for(int i=0;i<=n-2;i++)
        {
            fn=fn_1+fn_2;
            fn_2=fn_1;
            fn_1=fn;
        }
        return fn;
    }
};
