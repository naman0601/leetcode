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
                int up=matrix[i][j]+prev[j];
                int dul=matrix[i][j];
                if(j>0)
                    dul+=prev[j-1];
                else
                    dul+=1e9;
                int dur=matrix[i][j];
                if(j<n-1)
                    dur+=prev[j+1];
                else
                    dur+=1e9;
                cur[j]=mini(up,dul,dur);
            }
            prev=cur;
        }
        
        for(int j=0;j<n;j++){
            minimum=min(minimum,prev[j]);
        }
        return minimum;
    }
};