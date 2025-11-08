class Solution {
  public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void dfs(int node, vector<vector<int>> &adj_list ,vector<int> &vis){
        vis[node] = 1;
        temp.push_back(node);
        for(auto i : adj_list[node]){
             if(!vis[i]){
                dfs(i,adj_list,vis);
          }
        }
    }
   
    
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj_list(V);
        for(auto i : edges){
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }
        vector<int>vis(V,0);
        for(int i = 0 ; i < V ; i++){
            temp.clear();
            if(!vis[i]){
                dfs(i , adj_list ,vis);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
