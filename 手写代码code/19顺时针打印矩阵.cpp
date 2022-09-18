class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int>res;
        if(matrix.empty()||matrix[0].empty())return res;
        int xst=0,xed=matrix[0].size()-1,yst=0,yed=matrix.size()-1;
        while(1)
        {
            if(xst>xed||yst>yed)break;
            for(int i=xst;i<=xed;i++)
               res.push_back(matrix[yst][i]);
            yst++;
            if(xst>xed||yst>yed)break;
            for(int i=yst;i<=yed;i++)
               res.push_back(matrix[i][xed]);
            xed--;
            if(xst>xed||yst>yed)break;
            for(int i=xed;i>=xst;i--)
               res.push_back(matrix[yed][i]);
            yed--;
            if(xst>xed||yst>yed)break;
            for(int i=yed;i>=yst;i--)
               res.push_back(matrix[i][xst]);
            xst++;
        }
        return res;
    }
};
