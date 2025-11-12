class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        vector<int>dist(n,-1);
        queue<int> q; 
        q.push(src);
        dist[src] = 0 ;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(dist[it]==-1){
                q.push(it);
                dist[it] = 1 + dist[node];
                }
            }
        }
        return dist;
    }
};