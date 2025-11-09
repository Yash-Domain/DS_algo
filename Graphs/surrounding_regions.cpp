class Solution {
public:
    int n, m;
    void dfs(int r, int c , vector<vector<char>>& board ,vector<vector<int>> &vis){
        vis[r][c] = 1;
        int drow[] = {-1 , 0 , 1 ,0};
        int dcol[] = {0 , 1 , 0 , -1};
        for(int i = 0 ; i < 4 ; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m 
            && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
         n = board.size();
         m = board[0].size();
        vector<vector<int>>vis(n , vector<int>(m,0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if((i==0|| j == 0 || i == n-1 || j == m-1) 
                && vis[i][j] == 0 && board[i][j] == 'O'){
                    dfs(i,j,board,vis);
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};