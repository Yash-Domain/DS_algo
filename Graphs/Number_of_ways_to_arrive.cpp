class Solution {
public:
    typedef pair<long long,int> p;
    int m = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<p>>adj(n);
        for(auto &i : roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int>path(n,0);
        vector<long long>dist(n,LLONG_MAX);
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});
        dist[0] = 0;
        path[0] = 1; // this is new one path from source is generated 
        while(!pq.empty()){
            auto[dis,node] = pq.top();
            pq.pop();
            for(auto &it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dis + wt < dist[v]){
                    dist[v] = dis + wt;
                    pq.push({dist[v],v});
                    path[v] = path[node] % m ;
                }
                else if (dis + wt == dist[v]){
                    path[v] = (path[v] + path[node]) % m;
                }
            }
        }
        return path[n-1] % m;
    }
};