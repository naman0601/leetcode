class Solution {
public:
    int f(int i1,int j1,int i2,int j2,int n,vector<vector<int>> &grid,int dp[50][50][50][50]){
        if(i1>n || i2>n || j1>n || j2>n || grid[i1][j1]==-1 || grid[i2][j2]==-1)
            return -1e9;
        if(i1==n && j1 ==n)
            return grid[i1][j1];
        if(dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];
        int c=0;
        if(i1==i2 && j1==j2)
            c+=grid[i1][j1];
        else
            c+=grid[i1][j1]+grid[i2][j2];
        
        int fir=f(i1+1,j1,i2+1,j2,n,grid,dp);
        int sec=f(i1+1,j1,i2,j2+1,n,grid,dp);
        int thi=f(i1,j1+1,i2+1,j2,n,grid,dp);
        int fort=f(i1,j1+1,i2,j2+1,n,grid,dp);
        c+=max(max(fir,sec),max(thi,fort));
        
        return dp[i1][j1][i2][j2]=c;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int dp[50][50][50][50];
		memset(dp, -1, sizeof dp);
        int n=grid.size();
        int r=f(0,0,0,0,n-1,grid,dp);
        if(r<0)
            return 0;
        else
            return r;
    }
};