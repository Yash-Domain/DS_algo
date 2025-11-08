class Solution {
public:
    void dfs(int node ,vector<vector<int>> &adj , vector<int> &vis){
        vis[node] = 1;
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 1 && i != j){
                        adj[i].push_back(j);
                       // adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int>vis(n,0);
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};