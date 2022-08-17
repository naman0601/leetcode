class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
         int n1=s1.length();
        int n2=s2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2=1;ind2<=n2;ind2++){
               if(s1[ind1-1]==s2[ind2-1] )
                  dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
               else
                   dp[ind1][ind2]=max(dp[ind1][ind2-1],dp[ind1-1][ind2]);
            }
        }
        string s;
        int i=n1,j=n2;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                s+=s1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    s+=s1[i-1];
                    i--;
                }
                else{
                    s+=s2[j-1];
                    j--;
                }
            }
        }
        while(i>0){
            s+=s1[i-1];
            i--;
        }
        while(j>0){
            s+=s2[j-1];
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};