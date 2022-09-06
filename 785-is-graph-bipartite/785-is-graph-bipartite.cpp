class Solution {
public:
    bool checkDfs(int src,vector<int> &color,vector<vector<int>> graph){
        for(auto c:graph[src]){
            if(color[c]==-1){
                color[c]=!color[src];
                if(checkDfs(c,color,graph)==false) return false;
            }
            else if(color[c]==color[src]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=1;
                if(checkDfs(i,color,graph)==false) return false;
            }
        }
        return true;
    }
};