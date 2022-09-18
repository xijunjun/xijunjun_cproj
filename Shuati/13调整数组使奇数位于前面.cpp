//使用空间复杂度O(1)的稳定排序算法：冒泡、插入排序
class Solution {
public:
    void reOrderArray(vector<int> &array) {
           for(int i=1;i<array.size();i++)
           {
               for(int j=i;j>=1;j--)
               {
                   if((array[j-1]&1)<(array[j]&1))
                       swap(array[j-1],array[j]);
                   else 
                       break;
               }
           }
    }
}; 
//空间复杂度O(n)的解法，正反向各遍历一次
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int ind=0;
        vector<int> b(array);
        for(int i=0;i<b.size();i++)
            if(b[i]&1)array[ind++]=b[i];
        ind=b.size()-1;
        for(int i=b.size()-1;i>=0;i--)
            if(!(b[i]&1))array[ind--]=b[i];
    }
};
