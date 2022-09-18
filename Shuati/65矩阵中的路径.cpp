class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        vector<vector<bool>>visited(rows,vector<bool>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(isequal(matrix,rows,cols,str,j,i,visited,0))
                    return true;
            }
        }
        return false;
    }
    bool isequal(char* matrix, int rows, int cols, char* str,int x,int y,vector<vector<bool>>&visited,int ind)
    {
        if(x<0||y<0||x>=cols||y>=rows||visited[y][x]==1||*(str+ind)!=*(matrix+y*cols+x))return false;
        if(ind==strlen(str)-1)return true;
        visited[y][x]=1;
        if(isequal(matrix,rows,cols,str,x-1,y,visited,ind+1)||
          isequal(matrix,rows,cols,str,x+1,y,visited,ind+1)||
          isequal(matrix,rows,cols,str,x,y-1,visited,ind+1)||
          isequal(matrix,rows,cols,str,x,y+1,visited,ind+1))
            return true;
        visited[y][x]=0;
        return false;
    }
};
