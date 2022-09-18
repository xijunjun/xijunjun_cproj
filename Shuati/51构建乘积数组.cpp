class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len=A.size();
        vector<int>lt(A.size(),1),rt(A.size(),1);
        for(int i=1;i<A.size();i++)
        {
            lt[i]=lt[i-1]*A[i-1];
            rt[len-1-i]=rt[len-i]*A[len-i];
        }
        vector<int>res(len);
        for(int i=0;i<len;i++)
            res[i]=lt[i]*rt[i];
        return res;
     }
};
