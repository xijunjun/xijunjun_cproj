class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.empty())return ;
        *num1=0;
        for(int i=0;i<data.size();i++)
           *num1^=data[i];
        int flag=1;
        while(!(flag&*num1))
            flag=flag<<1;
        *num1=*num2=0;
        for(int i=0;i<data.size();i++)
        {
            if(data[i]&flag)
                *num1^=data[i];
            else 
                *num2^=data[i];
        }
    }
};
