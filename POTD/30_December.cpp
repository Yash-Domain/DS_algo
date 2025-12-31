//brute unclean 
class Solution {
public:
    int n, m;

    bool isValid(int start_i, int start_j, vector<vector<int>>& grid) {
        if (start_i + 2 >= n || start_j + 2 >= m)
            return false;

        // distinct 1-9
        vector<int> vec(9, 0);

        for (int i = start_i; i <= start_i + 2; i++) {
            for (int j = start_j; j <= start_j + 2; j++) {
                int num = grid[i][j];
                if (num > 9 || num == 0) {
                    return false;
                }
                vec[num - 1]++;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (vec[i] != 1) {
                return false;
            }
        }

        int sum = 0;
        // finding single col
        for (int i = start_i; i <= start_i + 2; i++) {
            sum += grid[i][start_j];
        }

        // row comparison
        for (int i = start_i; i <= start_i + 2; i++) {
            int row_sum = 0;
            for (int j = start_j; j <= start_j + 2; j++) {
                row_sum += grid[i][j];
            }
            if (row_sum != sum)
                return false;
        }

        // col comparison
        for (int j = start_j; j <= start_j + 2; j++) {
            int col_sum = 0;
            for (int i = start_i; i <= start_i + 2; i++) {
                col_sum += grid[i][j];
            }
            if (col_sum != sum)
                return false;
        }

        // diagonal
        int main_diagonal = 0;
        int sec_diagonal = 0;

        for (int k = 0; k < 3; k++) {
            main_diagonal += grid[start_i + k][start_j + k];
            sec_diagonal += grid[start_i + k][start_j + 2 - k];
        }

        if (sec_diagonal != sum || main_diagonal != sum) {
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isValid(i, j, grid)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

//optimal clean 
class Solution {
public:
    bool isValid(int r, int c, vector<vector<int>>& grid) {
        unordered_set<int> st;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[r + i][c + j];
                if (num == 0 || num > 9 || st.count(num)) {
                    return false;
                } else {
                    st.insert(num);
                }
            }
        }

        int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        // row and col
        for (int i = 0; i < 3; i++) {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] !=
                sum) {
                return false;
            }

            if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] !=
                sum) {
                return false;
            }
        }

        // main and second diagonal

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum) {
            return false;
        }

        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum) {
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (isValid(i, j, grid)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};