class Solution {
public:
    int f(vector<vector<int>> &v,int r,int c,vector<vector<int>> &dp){
        if(r<0 || c<0) return 0;
        if(v[r][c]==1) return 0;
        if(r==0 && c==0) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        return dp[r][c]=f(v,r-1,c,dp)+f(v,r,c-1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]!=1){
                if(i==0 && j==0) dp[i][j]=1;
                else {
                    int up=0,left=0; 
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
            }
        }
        return dp[m-1][n-1];
    }
};