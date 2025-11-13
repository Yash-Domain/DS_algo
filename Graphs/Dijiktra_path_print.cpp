class Solution {
  public:
    typedef pair<int,int> p ;
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<p>>adj(n+1);
        for(auto i : edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int>dist(n+1);
        vector<int>parent(n+1);
        for(int i = 1 ; i <= n ; i++){
            parent[i] = i;
            dist[i] = 1e9;
            
        }
        
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,1});
        dist[1] = 0 ;
        
        while(!pq.empty()){
            auto[dis,node] = pq.top();
            pq.pop();
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dis + wt < dist[v]){
                    dist[v] = dis + wt ;
                    pq.push({dist[v] , v});
                    parent[v] = node;
                }
            }
        }
        int node = n ;
        if(dist[node]==1e9) return {-1};
        vector<int>path;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        return path;
        
    }
};