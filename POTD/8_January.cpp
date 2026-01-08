class Solution {
public:
    typedef long long ll;
    int n, m;

    ll solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if (j == m || i == n) {
            return -1e17;
        }

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        // both taken
        ll prod = nums1[i] * nums2[j];
        ll take = max(prod, prod + solve(i + 1, j + 1, nums1, nums2, dp));

        // nums1 taken nums2 not
        ll case_1 = 0 + solve(i, j + 1, nums1, nums2, dp);
        // nums2 taken nums1 not
        ll case_2 = 0 + solve(i + 1, j, nums1, nums2, dp);

        // both not taken is in above 2 cases

        return dp[i][j] = max(take, max(case_1, case_2));
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        return solve(0, 0, nums1, nums2, dp);
    }
};

// LCS way
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m+1, -1e9));

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int prod = nums1[i-1]*nums2[j-1];

                dp[i][j] = max(prod,prod + dp[i-1][j-1]);

                dp[i][j] = max(dp[i][j],dp[i-1][j]);

                dp[i][j] = max(dp[i][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};