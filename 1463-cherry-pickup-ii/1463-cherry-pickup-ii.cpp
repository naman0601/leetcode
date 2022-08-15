class Solution {
public:
   
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int dp[n][m][m];
        memset(dp,0,sizeof dp);
        for(int j=0;j<m;j++){
           for(int k=0;k<m;k++){
               if(j==k)
                   dp[n-1][j][k]=grid[n-1][k];
               else
                   dp[n-1][j][k]=grid[n-1][j]+grid[n-1][k];
           }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                     int maxi=-1e9;
                     for(int i1=-1;i1<2;i1++){
                        for(int i2=-1;i2<2;i2++){
                            int val=0;
                            if(j==k)
                                val=grid[i][j];
                            else
                                val=grid[i][j]+grid[i][k];
                            if(i1+j>=0 && i2+k>=0 && i1+j<m && i2+k<m)
                                val+=dp[i+1][j+i1][k+i2];
                            else
                                val+=-1e9;
                            maxi=max(maxi,val);
                        }
                     }
                     dp[i][j][k]=maxi;       
                }
            }
        }
        return dp[0][0][m-1];
    }
};