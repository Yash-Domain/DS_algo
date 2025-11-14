class Solution {
  public:
    typedef pair<int,int>p;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<p>>adj(V);
        for(auto i : edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int>vis(V,0);
        pq.push({0,0});
        int tot = 0;
        while(!pq.empty()){
            auto[wt , node] = pq.top();
            pq.pop();
            if(vis[node] == 1) continue;
            vis[node] = 1 ;
            tot += wt;
            for(auto it : adj[node]){
                if(!vis[it.first]){
                    pq.push({it.second,it.first});
                }
            }
        }
        return tot ;
    }
};