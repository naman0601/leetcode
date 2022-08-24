class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>>& t,vector<vector<int>> &dp){
        if(j<0 || j>n) return 1e9;
        
        if(i==0)
            return t[0][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int fir=f(i-1,j,n,t,dp);
        int sec=f(i-1,j-1,n,t,dp);
        int thir=f(i-1,j+1,n,t,dp);
        
        return dp[i][j]=t[i][j]+min(sec,min(fir,thir));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),-1));
            mini=min(mini,f(matrix.size()-1,i,matrix.size()-1,matrix,dp));
        }
        return mini;
    }
};