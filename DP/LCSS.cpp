class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int maxi = -1e9;
        for(int i = 1 ; i < n + 1 ; i++){
            for(int j = 1 ; j < m + 1 ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxi = max(maxi,dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        if(maxi < -1e5) return 0;
        return maxi;
    }
};