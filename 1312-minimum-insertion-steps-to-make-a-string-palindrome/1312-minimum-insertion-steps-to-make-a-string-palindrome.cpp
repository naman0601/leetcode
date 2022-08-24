class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N=text1.length(),M=text2.length();
        vector<vector<int>> dp(N+1,vector<int>(M+1,0));
        for(int n=1;n<=N;n++){
            for(int m=1;m<=M;m++){
                if(text1[n-1]==text2[m-1]) 
                      dp[n][m]=1+dp[n-1][m-1];
                else
                      dp[n][m]=max(dp[n-1][m],dp[n][m-1]);
            }
        }
        return dp[N][M];
    }
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;
        return longestCommonSubsequence(s1,s2);
    }
    int minInsertions(string s) {
        return s.length()-longestPalindromeSubseq(s);
    }
};