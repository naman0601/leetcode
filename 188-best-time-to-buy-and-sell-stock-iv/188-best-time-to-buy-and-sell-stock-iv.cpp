class Solution {
public:
    int f(int ind,int transc,int limit,vector<int> prices,vector<vector<int>> &dp){
        if(ind==prices.size() || transc==limit) return 0;
        
        if(dp[ind][transc]!=-1) return dp[ind][transc];
        
        int profit=0;
        if(transc%2==0)//buy
        {
            profit=max(-prices[ind]+f(ind+1,transc+1,limit,prices,dp),f(ind+1,transc,limit,prices,dp));
        }    
        else{
            profit=max(prices[ind]+f(ind+1,transc+1,limit,prices,dp),f(ind+1,transc,limit,prices,dp));
        }
        
        return dp[ind][transc]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2*k,-1));
        return f(0,0,2*k,prices,dp);
    }
};