// brute force 
class Solution {
public:
    
    bool isValid(vector<vector<int>>& grid, int start_i, int start_j, int side) {
        int sum = 0;
        for (int i = start_i; i < start_i + side; i++) {
            sum += grid[i][start_j];
        }

        // col_sum
        for (int j = start_j; j < start_j + side; j++) {
            int col_sum = 0;
            for (int i = start_i; i < start_i + side; i++) {
                col_sum += grid[i][j];
            }
            if (col_sum != sum)
                return false;
        }

        // row_sum
        for (int i = start_i; i < start_i + side; i++) {
            int row_sum = 0;
            for (int j = start_j; j < start_j + side; j++) {
                row_sum += grid[i][j];
            }
            if (row_sum != sum)
                return false;
        }

        // main_diag
        int main_diag_sum = 0;
        for (int i = start_i; i < start_i + side; i++) {
            for (int j = start_j; j < start_j + side; j++) {
                if (i - start_i == j - start_j) {
                    main_diag_sum += grid[i][j];
                }
            }
        }
        if (main_diag_sum != sum)
            return false;

        //sec_diag
        int sec_diag_sum = 0;
        for (int i = start_i; i < start_i + side; i++) {
            for (int j = start_j; j < start_j + side; j++) {
                if ((i - start_i) + (j - start_j) + 1 == side) {
                    sec_diag_sum += grid[i][j];
                }
            }
        }
        if(sec_diag_sum != sum)
            return false;
        
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int side = min(n, m);
        int ans = 1;

        for (int k = side; k >= 2; k--) {
            for (int i = 0; i <= n - k; i++) {
                for (int j = 0; j <= m - k; j++) {
                    if (isValid(grid, i, j, k)) { // i ,j is start with side k
                        return k;
                    }
                }
            }
        }

        return ans;
    }
};

// optimal 
class Solution {
public:
    vector<vector<int>> row, col;
    bool isValid(vector<vector<int>>& grid, int start_i, int start_j,
                 int side) {
        int end_i = start_i + side - 1;
        int end_j = start_j + side - 1;

        // first col
        int sum = col[end_i][start_j] - (start_i > 0 ? col[start_i - 1][start_j] : 0);

        // col_sum
        for (int j = start_j; j < start_j + side; j++) {
            int col_sum = col[end_i][j] - (start_i > 0 ? col[start_i - 1][j] : 0);
            if (col_sum != sum) return false;
        }

        // row_sum
        for (int i = start_i; i < start_i + side; i++) {
            int row_sum = row[i][end_j] - (start_j > 0 ? row[i][start_j - 1]  : 0);
            if (row_sum != sum) return false;
        }

        // main_diag
        int main_diag_sum = 0;
        for(int d = 0 ; d < side ; d++){
            main_diag_sum += grid[d + start_i][d + start_j];
        }
        if (main_diag_sum != sum)
            return false;

        // sec_diag
        int sec_diag_sum = 0;
        for(int d = 0 ; d < side ; d++){
            sec_diag_sum += grid[d + start_i][start_j + side - 1 - d]; // cringy !!
        }                         // i == d == row so calculate col in terms of row
        if (sec_diag_sum != sum)  // i + j + 1 = side   
            return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        row.assign(n, vector<int>(m, 0));
        col.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i][j] = grid[i][j] + (j > 0 ? row[i][j - 1] : 0);
                col[i][j] = grid[i][j] + (i > 0 ? col[i - 1][j] : 0);
            }
        }

        int side = min(n, m);
        int ans = 1;

        for (int k = side; k >= 2; k--) {
            for (int i = 0; i <= n - k; i++) {
                for (int j = 0; j <= m - k; j++) {
                    if (isValid(grid, i, j, k)) { // i ,j is start with side k
                        return k;
                    }
                }
            }
        }
        return 1;
    }
};