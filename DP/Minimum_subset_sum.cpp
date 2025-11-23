class Solution {
  public:
    int n;
    void solve(vector<int>& nums, int sum, vector<vector<int>>& dp) {
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= sum; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    int minDifference(vector<int>& nums) {
        // Your code goes here
        n = nums.size();
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        solve(nums, sum, dp);
        vector<int> vec;
        int s1;
        for (int i = 0; i <= sum / 2; i++) {
            if (dp[n][i] == 1) {
                s1 = i;
            }
        }
        return sum - 2 * s1;
    }
};
