//推荐写法：队列
class Solution
{
public:
    int hash[256]={0};
    queue<char>q;
  //Insert one char from stringstream
    void Insert(char ch)
    {
         if(hash[ch]==0){
             q.push(ch);
             hash[ch]=1;
         }
        else hash[ch]=2;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!q.empty())
        {
            if(hash[q.front()]!=1)
                q.pop();
            else break;
        }
        if(q.empty())return '#';
        return q.front();
    }

};
//链表实现 
class Solution
{
public:
    int hash[256]={0};
    list<char>q;
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(hash[ch]==0)
        {
            q.push_back(ch);
            hash[ch]=1;
        }else if(hash[ch]==1)
        {
            auto it=q.begin();
            while(*it!=ch)
                 it++;
            q.erase(it); 
            hash[ch]=2;
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        if(q.empty())return '#';
        return *q.begin();
    }
};
