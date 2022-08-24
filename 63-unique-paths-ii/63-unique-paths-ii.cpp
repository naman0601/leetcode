class Solution {
public:
    int f(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>> &dp){
        if(i==0 && j==0 && obstacleGrid[i][j]==0)
            return 1;
        if(i<0 || j<0 || obstacleGrid[i][j]==1)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=f(obstacleGrid,i-1,j,dp)+f(obstacleGrid,i,j-1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(obstacleGrid,n-1,m-1,dp);
    }
};