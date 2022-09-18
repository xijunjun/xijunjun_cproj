//推荐写法，循环len次，每次使栈顶与待比较元素相等
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int>sta;
        int len=pushV.size(),ind=0;
        for(int i=0;i<len;i++)
        {
            while(1)
            {
                if(!sta.empty()&&sta.top()==popV[i])
                    break;
                if(ind==len)return false;
                sta.push(pushV[ind++]);
            }
            sta.pop();
        }
        return true;
    }
};
//先压后判，1、如果栈空或者栈顶不等于弹出值，一直压到相等或者压玩为止。2、栈顶与弹出值相等，pop栈，不等则返回false
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
         
        stack<int>sta;
        int j=0;
        for(int i=0;i<popV.size();i++)
        {
            if(sta.empty()||sta.top()!=popV[i])
             while(j<popV.size())   
             {
                 sta.push(pushV[j]);
                 j++;
                 if(sta.top()==popV[i])break;
             }
            if(sta.top()==popV[i])
                sta.pop();
            else return false;
        }
        return true;
    }
};
