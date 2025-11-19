class Solution {
public:
    int t[201][201];
    int solve(int i, int j ,vector<vector<int>>& grid){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1e9;
        if(t[i][j] != -1) return t[i][j];
        int up   =  solve(i-1,j,grid);
        int down =  solve(i,j-1,grid);
        return t[i][j] = grid[i][j] + min(up,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(m-1,n-1,grid);
    }
};