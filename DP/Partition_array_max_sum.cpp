class Solution {
public:
    int n ;
    
    int f(int ind , vector<int> &arr, int k, vector<int>&dp){
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int ans = INT_MIN;
        int maxi_ele = INT_MIN;
        for(int j = ind ; j < min(n,ind+k) ; j++){
            maxi_ele = max(arr[j],maxi_ele);
            int sum  = (j - ind + 1)* maxi_ele + f(j+1,arr,k,dp);
            ans = max(ans,sum);
        }
        return dp[ind] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int>dp(n,-1);
        return f(0,arr,k,dp);
    }
};