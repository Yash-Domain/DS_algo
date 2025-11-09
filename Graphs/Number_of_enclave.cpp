class Solution {
public:
    int n , m;
    void dfs(int r , int c ,vector<vector<int>>& grid, vector<vector<int>> &vis ){
        vis[r][c] = 1 ;
        int drow[] = {-1 , 0 , 1 , 0};
        int dcol[] = {0 , -1 , 0 , 1};
        for(int i = 0 ; i < 4 ; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                        dfs(nrow , ncol , grid , vis);
                    }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(i == 0 || i == n-1 || j == 0 || j == m -1){
                    if(!vis[i][j] && grid[i][j] == 1){
                        dfs(i,j,grid,vis);
                    }
                }
            }
        }
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(!vis[i][j]  && grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};