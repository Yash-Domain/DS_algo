class Solution {
public:
    const long long MOD = 1e18;
    int count(vector<int>& nums, int W, int n){
        vector<vector<long long>>dp(n+1,vector<long long>(W+1));
        for(int j = 1 ; j < W + 1 ; j++) dp[0][j] = 0;
        for(int i = 0 ; i < n + 1 ; i++)   dp[i][0] = 1;
        for(int i = 1 ; i < n +1 ; i++){
            for(int j = 1 ; j < W + 1 ; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = (dp[i][j-nums[i-1]] + dp[i-1][j]) % MOD;
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][W];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return count(coins,amount,n);
    }
};