class Solution {
public:
    void dijiktra(int src, vector<vector<pair<int, int>>>& adj, vector<vector<int>>& dist) {
        dist[src][src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>pq;

        pq.push({0, src});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            for (auto& it : adj[node]) {
                if (dis + it.second < dist[src][it.first]) {
                    dist[src][it.first] = dis + it.second;
                    pq.push({dist[src][it.first], it.first});
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
                            
        vector<vector<pair<int, int>>> adj(26);

        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].push_back({v, cost[i]});
        }

        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));

        for (int i = 0; i < 26; i++) {
            dijiktra(i, adj, dist);
        }

        long long ans = 0;

        for (int i = 0; i < source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (dist[u][v] != INT_MAX) {
                ans += dist[u][v];
            } else {
                return -1;
            }
        }

        return ans;
    }
};