class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int si=0,maxl=1;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                si=i;
                maxl=2;
            }
        for(int k=3;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                int j=i+k-1;
                if(dp[i+1][j-1] && s[i]==s[j]){
                     dp[i][j]=true;
                     if(k>maxl){
                         si=i;
                         maxl=k;
                     }
                }
            }
        }
        return s.substr(si,maxl);
    }
};