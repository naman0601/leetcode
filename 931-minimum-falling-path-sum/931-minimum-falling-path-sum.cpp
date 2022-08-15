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

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int minimum=INT_MAX;
        int n=matrix.size();  
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int j=0;j<n;j++)
            dp[0][j]=matrix[0][j];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+dp[i-1][j];
                int dul=matrix[i][j];
                if(j>0)
                    dul+=dp[i-1][j-1];
                else
                    dul+=1e9;
                int dur=matrix[i][j];
                if(j<n-1)
                    dur+=dp[i-1][j+1];
                else
                    dur+=1e9;
                dp[i][j]=mini(up,dul,dur);
            }
        }
        
        for(int j=0;j<n;j++){
            minimum=min(minimum,dp[n-1][j]);
        }
        return minimum;
    }
};