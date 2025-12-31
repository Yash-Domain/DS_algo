// brute force n*n
class Solution {
public:

    void dfs(int r , int c , vector<vector<int>> &grid ,vector<vector<int>> &vis ,bool &path){
        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;

        if(r == n - 1){
            path = true;
            return;
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        for(int i = 0 ; i < 4 ; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0){
                dfs(nrow,ncol,grid,vis,path);
            }
        }
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();

        vector<vector<int>> grid(row, vector<int>(col, 0));

        int i = 0;

        while (i < n) {
            int row_to_change = cells[i][0] - 1;
            int col_to_change = cells[i][1] - 1;

            grid[row_to_change][col_to_change] = 1;
            int k = 0;
            for (; k < col; k++) {
                vector<vector<int>> vis(row,vector<int>(col,0));
                bool path = false;
                if (grid[0][k] == 0) {
                    dfs(0,k,grid,vis,path);
                }

                if(path == true){
                    break;
                }
            }

            if(k == col){
                return i;
            }

            i++;
        }

        return n;

    }
};
// optimal nlogn
class Solution {
public:
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        grid[r][c] = 1;

        if (r == n - 1) {
            return true;
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 0) {
                if (dfs(nrow, ncol, grid) == true) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isValid(int mid, vector<vector<int>>& cells, int row, int col) {

        vector<vector<int>> grid(row, vector<int>(col, 0));

        for (int i = 0; i <= mid; i++) {
            int row_to_change = cells[i][0] - 1;
            int col_to_change = cells[i][1] - 1;

            grid[row_to_change][col_to_change] = 1;
        }

        for (int k = 0; k < col; k++) {
            if (grid[0][k] == 0 && dfs(0, k, grid)) {
                return true;
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();

        int l = 0, r = n - 1;

        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(mid, cells, row, col)) {
                ans = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};