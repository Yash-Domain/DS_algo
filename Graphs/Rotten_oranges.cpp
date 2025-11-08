class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));  //vector<int>(m, 0) one row
        queue<tuple<int,int,int>> q;
        int tmax = 0;
 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    vis[i][j] = 2;
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            auto [r,c,t] = q.front();
            q.pop();
            tmax = t;
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && 
                vis[nrow][ncol] == 0  && grid[nrow][ncol] == 1){
                    q.push({nrow,ncol,t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1 ) return -1;
            }
        }
        return tmax;
    }
};