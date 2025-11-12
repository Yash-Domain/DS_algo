// User Function Template
class Solution {
  public:
    typedef pair<int,int>p ;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<p>> adj(V);
        for(auto i : edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<p , vector<p>, greater<p>>pq;
        pq.push({0,src});
        vector<int>dist(V);
        for(int i = 0 ; i < V ; i++) dist[i] = 1e9;
        dist[src] = 0;
        
        while(!pq.empty()){
            auto [dis , node] = pq.top();
            pq.pop();
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second ;
                
                if(dis + wt < dist[v]){
                    dist[v] = dis + wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};

// using_set
// User Function Template
class Solution {
  public:
    typedef pair<int,int>p ;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<p>> adj(V);
        for(auto i : edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        //priority_queue<p , vector<p>, greater<p>>pq;
        set<p>pq;
        pq.insert({0,src});
        vector<int>dist(V);
        for(int i = 0 ; i < V ; i++) dist[i] = 1e9;
        dist[src] = 0;
        
        while(!pq.empty()){
            auto [dis , node] = *(pq.begin());
            pq.erase(pq.begin());
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second ;
                
                if(dis + wt < dist[v]){
                    if(dist[v] != 1e9) pq.erase({dist[v],v});
                    dist[v] = dis + wt;
                    pq.insert({dist[v],v});
                }
            }
        }
        return dist;
    }
};