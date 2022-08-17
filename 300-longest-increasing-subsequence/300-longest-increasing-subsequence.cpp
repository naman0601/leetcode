class Solution {
public:
    int f(int ind,vector<int> &a,int nex,vector<vector<int>> &dp,int size){
        if(ind<0)
            return 0;
        if(dp[ind][nex]!=-1) return dp[ind][nex];        
        int notpick=f(ind-1,a,nex,dp,size);
        int pick=0;
        if(nex==size || a[ind]<a[nex])
            pick=1+f(ind-1,a,ind,dp,size);
        return dp[ind][nex]=max(pick,notpick);        
    }
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
         vector<vector<int>> dp(n,vector<int>(n+1,-1));
         return f(n-1,a,n,dp,n);
    }
};