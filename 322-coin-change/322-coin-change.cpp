class Solution {
public:
    int f(int n,vector<int> &coins,int amount,vector<vector<int>> &dp){
        if(amount==0)
            return 0;
        if(n==0){
            if(amount%coins[0]==0)
                return amount/coins[0];
            else
                return 1e9;
        }
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        int nottake=0+f(n-1,coins,amount,dp);
        int take=1e9;
        if(coins[n]<=amount)
            take=1+f(n,coins,amount-coins[n],dp);
        return dp[n][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int res=f(n-1,coins,amount,dp);
        if(res>=1e9)
           return -1 ;
        else
            return res;
    }
};