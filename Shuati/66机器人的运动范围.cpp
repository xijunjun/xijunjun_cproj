class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int cnt=0;
        vector<vector<bool>>visited(rows,vector<bool>(cols,0));
        Trav( threshold, rows, cols,0,  0, cnt,visited);
        return cnt;
    }
    void Trav(int th,int rows,int cols,int x, int y,int &cnt,vector<vector<bool>>&visited)
    {
        if(x<0||y<0||x>=cols||y>=rows||visited[y][x]==1||!isval(x,y,th))return ;
        cnt++;
        visited[y][x]=1;
        Trav( th, rows, cols, x+1,  y, cnt,visited);
        Trav( th, rows, cols, x-1,  y, cnt,visited);
        Trav( th, rows, cols, x,  y+1, cnt,visited);
        Trav( th, rows, cols, x,  y-1, cnt,visited);
    }
    bool isval(int x, int y,int th)
    {
        string nums=to_string(x)+to_string(y);
        for(int i=0;i<nums.size();i++)
            th-=nums[i]-'0';
        return th>=0;
    }
};
