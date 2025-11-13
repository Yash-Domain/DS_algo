class Solution {
public:
    typedef pair<int,int> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<p>>adj(n);
        for(auto i : flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        queue<tuple<int,int,int>>q;
        vector<int>dist(n,1e9);
        q.push({0,src,0});
        dist[src] = 0; 
        while(!q.empty()){
            auto[dis , node , lvl] = q.front();
            q.pop();
            if(lvl > k) continue;
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dis + wt < dist[v]){
                    dist[v] = dis + wt;
                    q.push({dist[v],v,lvl+1});
                }
            }
        }   
        if(dist[dst] != 1e9) return dist[dst];
        return -1;
    }
};