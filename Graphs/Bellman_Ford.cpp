// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src] = 0;
        
        // performing N-1 iterations
        for(int i = 0 ; i < V ; i++){
            for(auto &i : edges){
                int u = i[0];
                int v = i[1];
                int wt = i[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // N th iteration
        for(auto &i : edges){
                int u = i[0];
                int v = i[1];
                int wt = i[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    return {-1};
                }
            }
        return dist;
    }
};
