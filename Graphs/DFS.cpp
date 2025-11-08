// O(N) + O(2E)
// O(3N)
class Solution {
  public:
    vector<int> ans;
    void dfs(int node , vector<vector<int>>& adj,vector<int> &vis ){
        vis[node] = 1;
        ans.push_back(node);
        for(auto &i : adj[node]){
            if(!vis[i]){
            dfs(i,adj,vis);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int>vis(n,0);
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};