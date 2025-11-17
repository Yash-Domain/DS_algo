class Solution {
public:
    int timer = 1;
    vector<vector<int>>bridges;
    void dfs(int node , int parent , vector<int>&vis, vector<int>&low ,vector<int>&tin,
                vector<vector<int>> &adj){
                    vis[node] = 1;
                    tin[node] = timer;
                    low[node] = timer;
                    timer++;
                    for(auto it : adj[node]){
                        if(it == parent) continue;
                        if(!vis[it]){
                            dfs(it, node, vis, low, tin, adj);
                            low[node] = min(low[it],low[node]);
                            if(low[it] > tin[node]){
                                bridges.push_back({it,node});
                            }
                        }
                        else{
                            low[node] = min(low[it],low[node]);
                        }
                    }
                }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n);
        vector<int>low(n);
        vector<int>tin(n);

        dfs(0,-1,vis,low,tin,adj);

        return bridges;
    }
};