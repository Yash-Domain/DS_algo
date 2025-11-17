// User function Template for C++

class Solution {
  public:
    vector<int>ans;
    int timer = 1;
    void dfs(int node, int parent,vector<int>&vis, vector<int>&low, 
                vector<int>&tin,vector<int> adj[],vector<int>&mark){
                    vis[node] = 1;
                    tin[node] = low[node] = timer;
                    timer++;
                    int child = 0;
                    for(auto it : adj[node]){
                        if(it == parent) continue;
                        if(!vis[it] ){
                            dfs(it,node,vis,low,tin,adj,mark);
                            low[node] = min(low[node],low[it]);
                            if(low[it] >= tin[node] && parent != -1){
                                mark[node] = 1;
                            }
                            child++;
                        }
                        else{
                            low[node] = min(low[node],tin[it]);  
                        }
                    }
                    if(child > 1 && parent == -1){
                        mark[node] = 1;
                    }
                }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        vector<int>low(V);
        vector<int>tin(V);
        vector<int>mark(V,0);
        dfs(0,-1,vis,low,tin,adj,mark);
        for(int i = 0 ; i < V ;i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};