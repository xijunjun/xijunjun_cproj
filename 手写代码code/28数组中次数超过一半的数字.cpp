//推荐写法
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())return 0;
        int st=0,ed=0,target=numbers.size()/2,p,cnt=0;
        while(1)
        {
            p=partition(numbers,st,ed);
            if(p==target)break;
            if(p<target)st=p+1;
            else ed=p-1;
        }
        for(int i=0;i<numbers.size();i++)
            if(numbers[i]==numbers[p])
                cnt++;
        if(cnt>=target+1)return numbers[p];
        return 0;
    }
    int partition(vector<int>&a,int st,int ed)
    {
        int insert_index=st;
        swap(a[st],a[ed]);
        for(int i=st;i<ed;i++)
            if(a[i]<=a[ed])
                swap(a[i],a[insert_index++]);
        swap(a[ed],a[insert_index]);
        return insert_index;
    }
};
//技巧写法：抵消法
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())return 0;
        int num,cnt=0;
        for(int i=0;i<numbers.size();i++)
        {
            if(cnt==0){
                cnt++;
                num=numbers[i];
            }
            else if(num==numbers[i])cnt++;
            else cnt--;
        }
        cnt=0;
        for(int i=0;i<numbers.size();i++)
            if(numbers[i]==num)cnt++;
        if(cnt>=numbers.size()/2+1)return num;
        return 0;   
    }
};
