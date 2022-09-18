class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
       if(sequence.empty())return false;
       if(sequence.size()<=2)return true;
        vector<int>vr,vl;
        int i=sequence.size()-2;
        int root=*sequence.rbegin();
        while(i>=0)
            {
            if(sequence[i]>=root)
                vr.push_back(sequence[i]);
            else break;
            i--;
            }
        while(i>=0)
            {
            if(sequence[i]<root)
                vl.push_back(sequence[i]);
            else return false;
             i--;
            }
        return (vl.empty()||VerifySquenceOfBST(vl))&&(vr.empty()||VerifySquenceOfBST(vr));
    }
};
