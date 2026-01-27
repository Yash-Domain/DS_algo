class Solution {
public:
    typedef pair<int, int> p;
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<p>> adj(n);

        for (auto& i : edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], 2 * i[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        priority_queue<p, vector<p>, greater<p>> pq;

        pq.push({0, 0}); // dist, node

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            for (auto& it : adj[node]) { // it.first is node , it.second is dist
                if (dis + it.second < dist[it.first]) {
                    dist[it.first] = dis + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};