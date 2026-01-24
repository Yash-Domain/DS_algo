class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int max_sum = INT_MIN;
        int l = 0;
        int r = n - 1;

        while(l < r) {
            max_sum = max(max_sum, nums[l] + nums[r]);
            l++;
            r--;
        }
        return max_sum;
    }
};