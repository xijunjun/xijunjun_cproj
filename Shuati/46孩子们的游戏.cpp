//递归
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1||m<1)return -1;
        if(n==1)return 0;
        return (m+LastRemaining_Solution(n-1, m))%n;
    }
};
//推荐写法，自底向上迭代
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1||m<1)return -1;
        int fn=0;
        for(int i=2;i<=n;i++)
            fn=(m+fn)%i;
        return fn;
    }
};
//环形链表
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1||m<1)return -1;
        list<int>pl;
        for(int i=0;i<n;i++)
            pl.push_back(i);
        auto it=pl.begin();
        for(int i=0;i<n-1;i++)
        {
            int k=(m-1)%(n-i);
            while(k-->0)
                it=++it!=pl.end()?it:pl.begin();
            auto tp=it;
            it=++it!=pl.end()?it:pl.begin();
            pl.erase(tp);               
        }
        return *pl.begin();
    }
};
