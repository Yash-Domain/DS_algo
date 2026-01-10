class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = int(s1[i - 1]) + dp[i - 1][j - 1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        int a = 0 ; 
        for(char ch : s1){
            a += int(ch);
        }

        int b = 0 ; 
        for(char ch : s2){
            b += int(ch);
        }

        return a + b - 2*dp[n][m];
    }
};