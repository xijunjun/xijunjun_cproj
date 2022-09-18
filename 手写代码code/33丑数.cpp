class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0)return 0;
        vector<int>a(index,1);
        int i2=0,i3=0,i5=0;
        for(int i=1;i<index;i++)
        {
            a[i]=min(min(2*a[i2],3*a[i3]),5*a[i5]);
            if(a[i]==2*a[i2])i2++;
            if(a[i]==3*a[i3])i3++;
            if(a[i]==5*a[i5])i5++;
        }
        return *a.rbegin();
    }
};
