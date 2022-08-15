class Solution {
public:
    int f(int i,int j1,int j2,int n,int m,vector<vector<int>> &grid,int dp[70][70][70]){
        if(j1<0 || j2<0 || j1>m || j2>m)
            return -1e9;
        if(i==n){
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=0;
        for(int k=-1;k<2;k++){
            for(int j=-1;j<2;j++){
                if(j1==j2)
                    maxi=max(maxi,grid[i][j1]+f(i+1,j1+k,j2+j,n,m,grid,dp));
                else
                    maxi=max(maxi,grid[i][j1]+grid[i][j2]+f(i+1,j1+k,j2+j,n,m,grid,dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int dp[70][70][70];
        memset(dp,-1,sizeof dp);
        return f(0,0,m-1,n-1,m-1,grid,dp);
    }
};