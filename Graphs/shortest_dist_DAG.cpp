// User function Template for C++
class Solution {
  public:
    void dfs(int node ,vector<vector<pair<int,int>>> &adj,vector<int> &vis,stack<int> &st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it.first]){
                dfs(it.first,adj,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v,wt});
        }
        vector<int>vis(V,0);
        stack<int>st;
        for(int i = 0 ; i < V ; i++){ // 
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int>dist(V);
        for(int i = 0 ; i < V ; i++) dist[i] = 1e9;
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }
        return dist;
    }
};

