class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1));
        for(int j = 1 ; j < target +1 ; j++){
            dp[0][j] = 0;
        }
        for(int i = 0 ; i < n+1 ; i++){
            dp[i][0] = 1;
        }

        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 0 ; j < target+1 ; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        if((sum + target) % 2 != 0 || abs(target) > sum) return 0;
        int s1 = (sum + target) / 2;
        return perfectSum(nums,s1);
    }
};