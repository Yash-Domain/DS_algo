class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
     
        vector<int>dp(n+1,0);
        dp[0] = 0;
        
        for(int i = 1 ; i < n ; i++){
        int left  = dp[i-1] + abs(height[i] - height[i-1]);
        int right = 1e9;
        if(i > 1)right = dp[i-2] + abs(height[i] - height[i-2]);
        dp[i] = min(left,right);
        }
        return dp[n-1]; 
    }
};


class Solution {
  public:
    int n ;
    int t[100001];
    int solve(vector<int> &height,int ind){
        if(ind == 0) return 0;
        if(t[ind] != -1) return t[ind];
        int left = solve(height,ind-1) + abs(height[ind] - height[ind-1]);
        int right = 1e9;
        if(ind > 1) right = solve(height,ind-2) + abs(height[ind] - height[ind-2]);
        return t[ind] = min(left, right);
    }
    int minCost(vector<int>& height) {
        // Code here
        n = height.size();
        memset(t,-1,sizeof(t));
        return solve(height,n-1);
    }
};