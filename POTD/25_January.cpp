class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), greater<int>());

        int ans = INT_MAX;

        for (int i = 0; i <= n - k; i++) {
            int min_socre = INT_MAX;
            int max_socre = INT_MIN;
            for (int j = i; j < i + k; j++) {
                min_socre = min(min_socre, nums[j]);
                max_socre = max(max_socre, nums[j]);
            }
            ans = min(ans, max_socre - min_socre);
        }

        return ans;
    }
};