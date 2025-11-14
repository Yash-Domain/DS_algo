class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for(int i = 0 ; i < n ; i++){
            dist[i][i] = 0;
        }
        for(int vis = 0 ; vis < n ; vis++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(dist[i][vis] == 1e9 || dist[vis][j] == 1e9) continue;
                    dist[i][j] = min(dist[i][j] ,dist[i][vis] + dist[vis][j]);
                }
            }
        }
        int cntmin = n;
        int city = -1;
        for(int i = 0 ; i < n ; i++){
            int cnt = 0;
            for(int j = 0 ; j < n ; j++){
                if(dist[i][j] <= k) cnt++;
            }
            if(cnt <= cntmin){
                cntmin = cnt;
                city = i;
            }
        }
    return city;
    }
};