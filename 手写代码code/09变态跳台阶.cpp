class Solution {
public:
    int jumpFloorII(int number) {
        return number>0?1<<--number:0;
    }
};
