class Solution {
public:
    
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<int> prev(m+1,0);
        
        for(int j=1;j<=m;j++) 
            prev[j]=j;         //insert
        
        for(int i=1;i<=n;i++){
            vector<int> cur(m+1,0);
            cur[0]=i;
            for(int j=1;j<=m;j++){
                 if(word1[i-1]==word2[j-1])
                    cur[j]=0+prev[j-1];
                 else
                    cur[j]=1+min(min(cur[j-1],prev[j]),prev[j-1]);
            }
            prev=cur;
        }
        
        return prev[m];
    }
};