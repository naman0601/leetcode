class Solution {
public:
    int f(vector<vector<int>> &triangle,int i,int j,int n,vector<vector<int>> &dp){
     if(i==n)  return triangle[n][j];
     if(dp[i][j]!=-1) return dp[i][j];   
     int down=triangle[i][j]+f(triangle,i+1,j,n,dp);
     int diagonal=triangle[i][j]+f(triangle,i+1,j+1,n,dp);
     return dp[i][j]=min(down,diagonal);   
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(triangle,0,0,n-1,dp);
    }
};