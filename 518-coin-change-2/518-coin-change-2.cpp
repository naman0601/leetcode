class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        for(int i=0;i<n;i++)
            dp[i][0]=1;
         for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
                dp[0][i]=1;
            else
                dp[0][i]=0;
        }
        for(int ind=1;ind<n;ind++){
            for(int amt=0;amt<=amount;amt++){
                int notpick=dp[ind-1][amt];
                int pick=0;
                if(coins[ind]<=amt)
                pick=dp[ind][amt-coins[ind]];
                dp[ind][amt]=pick+notpick;
            }
        }
       return dp[n-1][amount]; 
    }
};