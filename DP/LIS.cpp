//O(n*n)
class Solution {
public:
    int n;
    int LIS(int ind , int prev_ind , vector<int>&nums ,vector<vector<int>>&dp){
        if(ind >= n) return 0;

        if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        int not_take = 0 + LIS(ind+1,prev_ind,nums,dp);
        int take = 0;

        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
             take = 1 + LIS(ind+1,ind,nums,dp);
        }
        
        return dp[ind][prev_ind + 1] = max(not_take,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return LIS(0,-1,nums,dp) ;
    }
};

// 