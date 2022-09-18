class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.empty())return vector<string> ();
        if(str.size()==1)return vector<string> (1,str);
        sort(str.begin(),str.end());
        for(int i=0;i<str.size();i++)
        {
            if(i&&str[i]==str[0])continue;
            swap(str[0],str[i]);
            vector<string>tmp=Permutation(str.substr(1,str.size()-1)) ;
            for(int j=0;j<tmp.size();j++)
                res.push_back(string(1,str[0])+tmp[j]);
        }
        return res;
    }
};
//推荐写法
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.empty())return vector<string> ();
        sort(str.begin(),str.end());
        GenComb(str,0,res);
        return res;
    }
    void GenComb(string str,int st,vector<string> &res)
    {
        if(st==str.size()-1)
            res.push_back(str);
        for(int i=st;i<str.size();i++){
            if(i!=st&&str[i]==str[st])continue;
            swap(str[i],str[st]);
            GenComb(str,st+1,res);
            //swap(str[i],str[st]);
            //注意前面不需要swap回来，为了保证排列组合的升序输出，在遍历第st位的同时，
            //需要保证后面的字符串为升序，前面swap一次刚好符合要求
        }
    }
};
