class Solution {
  public:
    bool bfs(int src , vector<vector<int>> &adj , vector<int> &vis){
        queue<pair<int,int>> q ;
        q.push({src,-1});
        vis[src] = 1;
        
        while(!q.empty()){
            auto [node,parent] = q.front();
            q.pop();
            for(auto &it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it , node});
                }
                else if (it != parent ){
                    return true;
                }
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(V,0);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
             if( bfs(i,adj,vis) == true) return true;
            }
        }
        return false;
    }
};