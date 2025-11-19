class Solution {
public:
    int t[101][101];
   
    int solve(int i , int j ,vector<vector<int>>& grid){
        if(i < 0 || j < 0 ) return 0;
        if(grid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(t[i][j] != -1) return t[i][j];
        return t[i][j] = solve(i-1,j,grid) + solve(i,j-1,grid);
    }
     

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //if(grid[0][0] == 1) return 0; 
        memset(t,-1,sizeof(t));
        return solve(m-1,n-1,grid);
    }
};