class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0)return 1;
        if(exponent==1)return base;
        if(exponent<0)
            return 1/(Power(base,(-exponent)>>1)*Power(base,(-exponent+1)>>1));
         return Power(base,exponent>>1)*Power(base,(exponent+1)>>1);
    }
};
