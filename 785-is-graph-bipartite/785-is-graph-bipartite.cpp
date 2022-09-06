class Solution {
public:
    bool checkbipartite(int node,vector<vector<int>> graph,vector<int> &vis){
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(auto it:graph[n]){
                if(vis[it]==-1){
                    vis[it]=1-vis[n];
                    q.push(it);
                }
                else if(vis[it]==vis[n])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> vis(v,-1);
        for(int i=0;i<v;i++){
            if(vis[i]==-1){
                if(!checkbipartite(i,graph,vis))
                    return false;
            }
        }
        return true;
    }
};