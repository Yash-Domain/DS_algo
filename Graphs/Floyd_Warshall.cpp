// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        for(int vis = 0 ; vis < n ; vis++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(dist[i][vis] == 1e8 || dist[vis][j] == 1e8) continue;
                     dist[i][j] = min(dist[i][j],dist[i][vis] + dist[vis][j]);
                }
            }
        }
    }
};