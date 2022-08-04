class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]==2)
                    q.push({i,j});
        int c=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> p=q.front();
                q.pop();
                if(p.first-1>=0 && grid[p.first-1][p.second]==1){
                    grid[p.first-1][p.second]=2;
                    q.push({p.first-1,p.second});
                }
                if(p.second-1>=0 && grid[p.first][p.second-1]==1){
                    grid[p.first][p.second-1]=2;
                    q.push({p.first,p.second-1});
                }
                if(p.first+1<grid.size() && grid[p.first+1][p.second]==1){
                    grid[p.first+1][p.second]=2;
                    q.push({p.first+1,p.second});
                }
                if(p.second+1<grid[0].size() && grid[p.first][p.second+1]==1){
                    grid[p.first][p.second+1]=2;
                    q.push({p.first,p.second+1});
                }
            }
            c++;
        }
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]==1)
                    return -1;
        return c>=1?c-1:c;
    }
};