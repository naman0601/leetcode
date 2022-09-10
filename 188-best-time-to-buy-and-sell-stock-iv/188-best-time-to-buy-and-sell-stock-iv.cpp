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
        vector<vector<int>> dp(prices.size()+1,vector<int>(2*k+1,0));
        for(int ind=prices.size()-1;ind>=0;ind--){
            for(int transc=2*k-1;transc>=0;transc--){
                int profit=0;
                if(transc%2==0)//buy
                {
                    profit=max(-prices[ind]+dp[ind+1][transc+1],dp[ind+1][transc]);
                }    
                else{//sale
                    profit=max(prices[ind]+dp[ind+1][transc+1],dp[ind+1][transc]);
                }

                dp[ind][transc]=profit;
            }
        }
        return dp[0][0];
    }
};