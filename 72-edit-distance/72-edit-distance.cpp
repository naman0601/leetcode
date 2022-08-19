class Solution {
public:
    int f(int i,int j,string s,string t,vector<vector<int>> &dp){
        // if(j==0){
        //     if(i==0)
        //         return s[i]!=t[j];
        //     else if(i<0)
        //         return 1;
        //     else
        //         return (s[i]==t[j])? i:i+1;
        // }
        if(j<0){
            if(i<0)
                return 0;
            else 
                return i+1; //delete
        }
        
        if(i<0)  return j+1; //insert
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j])
            return dp[i][j]=0+f(i-1,j-1,s,t,dp);
        else
            return dp[i][j]=1+min(min(f(i,j-1,s,t,dp),f(i-1,j,s,t,dp)),f(i-1,j-1,s,t,dp));
        
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};