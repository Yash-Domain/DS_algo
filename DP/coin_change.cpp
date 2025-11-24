class Solution {
public:
    int solve(vector<int>& coins, int amount, int ind,vector<vector<int>>&dp){
        if(ind == 0){
            if(amount % coins[0] == 0){
                return amount/coins[0];
            }
            return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int not_take = solve(coins,amount,ind-1,dp);
        int take = 1e9;
        if(coins[ind] <= amount){
            take = 1 + solve(coins,amount-coins[ind],ind,dp);
        }
        return dp[ind][amount] = min(take,not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int a = solve(coins,amount,n-1,dp);
        if(a > 1e7) return -1;
        return a;
    }
};