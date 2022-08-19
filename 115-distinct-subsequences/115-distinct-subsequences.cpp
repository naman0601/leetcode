class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        
        //1 based indexing to avoid the index -1 case 
        vector<vector<double>> dp(n+1,vector<double> (m+1,0));
        
        for(int i=0;i<=n;i++)//returns 1 as all characters of 2nd string matched
            dp[i][0]=1;      //means we get subsequence of string 1 matched with str 2
        
        for(int j=1;j<=m;j++)//returns 0 as we have checked all characters of str1 but 
            dp[0][j]=0;     //still some character of string 1 is remaining  
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    /*if characters of both string match but there are two cases one to count that character of string 1 in subsequence or to find for other subsequence */
               else
                    dp[i][j]=dp[i-1][j]; 
            }
        }
        return (int)dp[n][m];
    }
};