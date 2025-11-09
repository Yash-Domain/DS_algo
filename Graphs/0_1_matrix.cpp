class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n , vector<int>(m,-1));
        int drow[] = {-1 , 0 , 1 , 0 };
        int dcol[] = {0, -1 , 0 , 1};
        queue<pair<int,int>> q;
        // start dfs from all 0's
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto [r , c] = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == -1){
                    vis[nrow][ncol] = 1 + vis[r][c];
                    q.push({nrow,ncol});
                }
            }
        }
        return vis;
    }
};