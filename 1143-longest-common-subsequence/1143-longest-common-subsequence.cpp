class Solution {
public:
    
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,0));
        
        for(int ind1=0;ind1<n1;ind1++){
            for(int ind2=0;ind2<n2;ind2++){
               if(s1[ind1]==s2[ind2] ){
                  dp[ind1][ind2]=1;
                  if(ind1>0 && ind2>0)
                      dp[ind1][ind2]+=dp[ind1-1][ind2-1];
               }
               else{
                   int choice1=0,choice2=0;
                   if(ind2>0)
                       choice1=dp[ind1][ind2-1];
                   if(ind1>0)
                       choice2=dp[ind1-1][ind2];
                   dp[ind1][ind2]=max(choice1,choice2);
               }
            }
        }
        return dp[n1-1][n2-1];
    }
};