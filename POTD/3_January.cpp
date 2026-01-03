// brute 
class Solution {
public:
    int cnt = 0;
    int const mod = 1e9 + 7;
    vector<vector<int>> dr = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();

        if (r == n - 1 && c == 2) {
            cnt = (cnt + 1) % mod;
        }

        int prev_color = grid[r][c];

        for (int i = 0; i < 4; i++) {
            int nrow = r + dr[i][0];
            int ncol = c + dr[i][1];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < 3) {
                if (grid[nrow][ncol] == -1) {
                    if (prev_color == 0) {
                        grid[nrow][ncol] = 1;
                        dfs(nrow, ncol, grid);

                        grid[nrow][ncol] = 2;
                        dfs(nrow, ncol, grid);

                    } else if (prev_color == 1) {
                        grid[nrow][ncol] = 0;
                        dfs(nrow, ncol, grid);

                        grid[nrow][ncol] = 2;
                        dfs(nrow, ncol, grid);
                    } else {
                        grid[nrow][ncol] = 0;
                        dfs(nrow, ncol, grid);

                        grid[nrow][ncol] = 1;
                        dfs(nrow, ncol, grid);
                    }
                }
            }
        }
    }

    int numOfWays(int n) {
        vector < vector<int>> grid(n, vector<int>(3, -1));

        for(int i = 0 ; i < 3 ; i++){
            grid[0][0] = i;
            dfs(0,0,grid);
        }

        return cnt;
    }
};

// optimal
class Solution {
public:
    int const mod = 1e9+7;

    int numOfWays(int n) {
        // two   = A B A
        // three = A B C 

        // DP PROBLEM   
        // base case 
        long long two   = 6; 
        long long three = 6;

        while(n > 1){ // loop running for n == 2 
            long long next_Two   = (3*two + 2*three) % mod;
            long long next_Three = (2*two + 2*three) % mod;
            two   = next_Two;   // same two becomes next_Two
            three = next_Three; // same logic when we did space optimisation 
            n--;
        }

        return (two + three) % mod;
    }
};