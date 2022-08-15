class Solution {
public:
    int minSumPathUtil(int i, int j,vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
  if(i==0 && j == 0)
    return matrix[0][0];
  if(i<0 || j<0)
    return 1e9;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = matrix[i][j]+minSumPathUtil(i-1,j,matrix,dp);
  int left = matrix[i][j]+minSumPathUtil(i,j-1,matrix,dp);
  
  return dp[i][j] = min(up,left);
  
}
   
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(i==0 && j==0) dp[i][j]=grid[i][j];
              else{
                  int up=grid[i][j];
                  if(i>0) up+=dp[i-1][j];
                  else
                      up+=1e9;
                  int left=grid[i][j];
                  if(j>0) left+=dp[i][j-1];
                  else
                      left+=1e9;
                  dp[i][j]=min(left,up);
              }
          }
        }
        return dp[m-1][n-1];
    }
};