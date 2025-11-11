// User function Template for C++

class Solution {
  public:
    int n,m;
    void dfs(int r , int c ,vector<vector<int>> &vis, vector<vector<int>>& grid, 
            int row0, int col0 ,vector<pair<int,int>> &vec ){
                vis[r][c] = 1 ;
            vec.push_back({r-row0,c-col0});
            int drow[] = {-1 , 0 , 1 , 0};
            int dcol[] = {0 , -1 , 0 , 1};
            for(int i = 0 ; i < 4 ; i++){
             int nrow = r + drow[i];
             int ncol = c + dcol[i];
             if(nrow >= 0 && ncol >=0 && ncol < m && nrow < n 
                    && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                        dfs(nrow , ncol , vis , grid , row0 , col0 ,vec);
                    }
                }
            }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
         n = grid.size();
         m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int>(m,0));
        unordered_set<vector<pair<int,int>>>st;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> vec;
                    dfs(i , j , vis , grid , i , j , vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
