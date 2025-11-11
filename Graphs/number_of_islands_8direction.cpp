class Solution {
  public:
    
    int n,m;
    void dfs(int r , int c ,vector<vector<char>>& grid,vector<vector<int>> &vis ){
        vis[r][c] = 1;
        
        int drow[] = {-1 , 0 , 1 , 0, -1, -1 , 1,  1};
        int dcol[] = {0 , 1 , 0 , -1, -1, 1 ,  1, -1};
        
        for(int i = 0 ; i < 8 ;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                &&!vis[nrow][ncol] && grid[nrow][ncol] == 'L'){
                    dfs(nrow,ncol,grid,vis);
                }
        }
    }
 
    int countIslands(vector<vector<char>>& grid) {
        // Code here
         n = grid.size();
         m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int cnt = 0; 
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == 'L'){
                        cnt++;
                        dfs(i,j,grid,vis);
                    } 
            }
        }
        return cnt ;
    }
};