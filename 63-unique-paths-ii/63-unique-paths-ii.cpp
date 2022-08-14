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
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return f(obstacleGrid,obstacleGrid.size()-1,obstacleGrid[0].size()-1,dp);
    }
};