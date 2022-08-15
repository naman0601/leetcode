class Solution {
public:
    
    int mini(int a,int b,int c){
        if(a<b){
            if(a<c)
                return a;
            else
                return c;
        }
        else{
            if(b<c)
                return b;
            else
                return c;
        }
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minimum=INT_MAX;
        int n=matrix.size();  
        vector<int> prev(n,0);
        
        for(int j=0;j<n;j++)
            prev[j]=matrix[0][j];
        
        for(int i=1;i<n;i++){
            vector<int> cur(n,0);
            for(int j=0;j<n;j++){
                int min1=INT_MAX;
                for(int k=0;k<n;k++){
                    if(k!=j){
                        min1=min(min1,matrix[i][j]+prev[k]);
                    }
                }
                cur[j]=min1;
            }
            prev=cur;
        }
        
        for(int j=0;j<n;j++){
            minimum=min(minimum,prev[j]);
        }
        return minimum;
        
    }
};