class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        bitset<0x0000ffff>hash(0);
        for(int i=0;i<length;i++)
        {
            if(hash[numbers[i]]==1){
                *duplication=numbers[i];
                return true;  
            } 
            hash[numbers[i]]=1;
        }
        return false;
    }
};
//推荐解法，根据数组的特性
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i=0;i<length;i++)
        {
            int key=numbers[i];
            if(key<0)key+=0x7fffffff;
            if(numbers[key]<0){
                * duplication=key;
                return true;
            }
            else 
                numbers[key]-=0x7fffffff;
        }
        return false;
    }
};
