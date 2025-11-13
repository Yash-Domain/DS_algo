class Solution {
public:
    typedef pair<int,int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i : times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dist(n+1,1e9);
        dist[k] = 0 ;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto[dis , node] = pq.top();
            pq.pop();

            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dis + wt < dist[v]){
                    dist[v] = dis + wt;
                    pq.push({dist[v],v});
                }
            }
        }
        int maxtime = -1 ;
        for(int i = 1 ; i <= n ; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            else {
                maxtime = max(maxtime,dist[i]);
            }
        }
    return maxtime;
    }
};