class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> v(matrix.size(),vector<int>(matrix[0].size(),0));
        int i1=0,j1=0;
        for(int j=0;j<matrix[0].size();j++)
        {  
            for(int i=matrix.size()-1;i>=0;i--)
             {
                 v[i1][j1++]=matrix[i][j];
             } 
            i1++;
            j1=0;
        }
        matrix=v;
    }
};