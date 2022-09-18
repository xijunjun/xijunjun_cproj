class Solution {
public:
    int jumpFloor(int number) {
        if(number<=2)return number;
        int fn,fn_1=2,fn_2=1;
        for(int i=0;i<=number-3;i++)
        {
            fn=fn_1+fn_2;
            fn_2=fn_1;
            fn_1=fn;
        }
        return fn;
    }
};
