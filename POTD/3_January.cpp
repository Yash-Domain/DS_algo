// brute 
class Solution {
public:
    int mod = 1e9 + 7;
    long long cnt = 0;

    void dfs(int row, int col, int n, vector<vector<int>>& grid) {
        // finished entire grid
        if (row == n) {
            cnt = (cnt + 1) % mod;
            return;
        }

        // move to next row
        if (col == 3) {
            dfs(row + 1, 0, n, grid);
            return;
        }

        for (int color = 0; color < 3; color++) {
            // check left
            if (col > 0 && grid[row][col - 1] == color) continue;
            // check up
            if (row > 0 && grid[row - 1][col] == color) continue;

            grid[row][col] = color;
            dfs(row, col + 1, n, grid);
            grid[row][col] = -1; // backtrack
        }
    }

    int numOfWays(int n) {
        vector<vector<int>> grid(n, vector<int>(3, -1));
        dfs(0, 0, n, grid);
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