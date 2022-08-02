class Solution {
public:
    string longestPalindrome(string s) {
        // int n=s.length();
        // bool table[n][n];
        // memset(table, false, sizeof(table));
        // int maxl=1;
        // for(int i=0;i<n;i++)
        //     for(int j=0;j<n;j++)
        //         table[i][j]=true;
        // int st=0;
        // for(int i=0;i<n-1;i++){
        //     if(s[i]==s[i+1]){
        //         table[i][i+1]=true;
        //         maxl=2;
        //         st=i;
        //     }
        // }
        // for(int k=3;k<=n;k++){
        //     for(int i=0;i<n-k+1;i++){
        //         int j=i+k-1;
        //         if(table[i+1][j-1] && s[i]==s[j]){
        //             table[i][j]=true;
        //             if(k>maxl){
        //                 maxl=k;
        //                 st=i;
        //             }
        //         }
        //     }
        // }
        // return s.substr(st,maxl);
        int n = s.size();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        int start = 0, maxL = 1;
        for(int i = 0 ; i < n; i++)
            dp[i][i] = true;
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxL = 2;
            }
        }
        for(int k = 3; k <= n; k++){
            for(int i = 0 ; i < n-k+1; i++){
                int j = i + k -1;
                if(dp[i+1][j-1] && s[i] == s[j]){
                    dp[i][j] = true;
                    if(k > maxL){
                        start = i;
                        maxL = k;
                    }
                }
            }
        }
        return s.substr(start, maxL);
    }
};