class Solution {
  public:
    bool dfs(int node , int parent ,vector<vector<int>> &adj,vector<int>&vis){
        vis[node] = 1 ;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it ,node , adj , vis) == true) return true;
            }
            else if (it != parent) return true;
        }
        return false;
    }
  
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(V,0);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis) == true) return true;
            }
        }
        return false ;
    }
};