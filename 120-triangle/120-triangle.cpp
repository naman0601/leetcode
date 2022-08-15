class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> prev(n,0);
        for(int j=0;j<=n-1;j++)
            prev[j]=triangle[n-1][j];
        for(int i=n-2;i>=0;i--){
            vector<int> cur(i+1,0);
            for(int j=i;j>=0;j--){
                int up=triangle[i][j]+prev[j];
                int dg=triangle[i][j]+prev[j+1];
                cur[j]=min(up,dg);
                
            }
            prev=cur;
        }
        return prev[0];
    }
};