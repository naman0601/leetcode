class Solution {
public:
    int mini(int a,int b,int c){
        if(a<b){
            if(a<c)
                return a;
            else
                return c;
        }
        else{
            if(b<c)
                return b;
            else
                return c;
        }
    }
    int f(int i,int j, vector<vector<int>>& m,int n,vector<vector<int>> &dp){
        if(j<0 || j>n) return 1e9;
        if(i==0) return m[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up=m[i][j]+f(i-1,j,m,n,dp);
        int dul=m[i][j]+f(i-1,j-1,m,n,dp);
        int dur=m[i][j]+f(i-1,j+1,m,n,dp);
        
        return dp[i][j]=mini(up,dul,dur);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minimum=INT_MAX;
        int n=matrix.size();  
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            minimum=min(minimum,f(n-1,j,matrix,n-1,dp));
        }
        return minimum;
    }
};