class Solution {
public:
     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        if (grid[0][0] == 0){
            q.push({0, 0});
            vis[0][0] = 1;
            }
        int drow[] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int dcol[] = {0, -1, 0, 1, -1, 1, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 8; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n 
                    && !vis[nrow][ncol] && grid[nrow][ncol] == 0 ){
                        vis[nrow][ncol] = 1 + vis[r][c];
                        q.push({nrow,ncol});
                    }
            }
        }
        if(vis[n-1][n-1] != 0) return vis[n-1][n-1];
        return -1 ;
    }
};