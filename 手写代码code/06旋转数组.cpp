//递归
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())return 0;
        return rec_find(rotateArray,0, rotateArray.size()-1);
    }
    int rec_find(vector<int> &a,int st, int ed)
    {
        int mid=(st+ed)/2;
        if(st>=ed||a[st]<a[ed])return a[st];
        if(a[mid]>=a[st]&&a[mid]>a[ed])
            return rec_find(a,mid+1, ed);
        if(a[mid]<=a[ed]&&a[mid]<a[st])
            return rec_find(a,st,mid);
         return *min_element(a.begin()+st,a.begin()+ed);
    }
};
//推荐写法：非递归
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        int st=0,ed=rotateArray.size()-1;
        vector<int>&a= rotateArray;
        while(1)
        {
            int mid=(st+ed)>>1;
           if(st>=ed||a[st]<a[ed])
               return a[st]; 
           if(a[mid]>=a[st]&&a[mid]>a[ed])
               st=mid+1;
            else if(a[mid]<=a[ed]&&a[mid]<a[st])
               ed=mid;
            else  break;
        }
        return *min_element(a.begin()+st,a.begin()+ed);
    }
};
