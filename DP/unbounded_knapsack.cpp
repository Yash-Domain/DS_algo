class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        for(int j = 0 ; j < W + 1; j++) dp[0][j] = 0;
        for(int i = 0 ; i < n + 1; i++) dp[i][0] = 0;
        for(int i = 1 ; i < n + 1 ; i++){
            for(int j = 1 ; j < W + 1; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][W];
    }
};