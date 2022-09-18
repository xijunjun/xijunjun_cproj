class Solution {
public:
    int Sum_Solution(int n) {
        int tp=0;
        n&&(tp=Sum_Solution(n-1)+n);
        return tp;
    }
};
