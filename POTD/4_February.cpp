class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        long long INF = -1e17;

        // all of this arrays are connected filling :) 
        vector<long long> dp0(n, INF), dp1(n, INF),
            dp2(n, INF), dp3(n, INF);

        long long ans = LLONG_MIN;

        dp0[0] = nums[0];

        for (int i = 1; i < n; i++) {

            if (nums[i] > nums[i - 1]) {
                dp1[i] = max(dp1[i - 1] + nums[i], dp0[i - 1] + nums[i]);

                // continue final increasing phase (dp3 -> dp3)
                // dp3[i] = dp3[i - 1] + nums[i]
                // OR start final increase after decrease (dp2 -> dp3)
                // dp3[i] = dp2[i - 1] + nums[i]
                dp3[i] = max(dp3[i - 1] + nums[i], dp2[i - 1] + nums[i]);

            } else if (nums[i] < nums[i - 1]) {
                dp2[i] = max(dp2[i - 1] + nums[i], dp1[i - 1] + nums[i]);
            }

            // always have a new start 
            dp0[i] = nums[i];

            ans = max(ans, dp3[i]);
        }

        return ans;
    }
};