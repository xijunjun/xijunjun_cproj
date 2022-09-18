//推荐写法
class Solution {
public:
    int Add(int num1, int num2)
    {
        int hsum=num1^num2,jinwei=(num1&num2)<<1;
        return jinwei==0?hsum:Add(hsum,jinwei);
    }
};
//奇葩写法
class Solution {
public:
    int Add(int num1, int num2)
    {
        char* a=reinterpret_cast<char *>(num1);
        return reinterpret_cast<long long>(&a[num2]);
    }
};
