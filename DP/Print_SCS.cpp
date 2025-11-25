class Solution {
public:
    void LCS(string s1, string s2, vector<vector<int>>& dp) {
        int n = s1.size(), m = s2.size();
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }

    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        LCS(s1, s2, dp);

        int i = n, j = m;
        string scs;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                scs.push_back(s1[i - 1]);
                i--, j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]){
                    scs.push_back(s1[i - 1]);
                    i--;
                }
                else{
                    scs.push_back(s2[j - 1]);
                    j--;
                }
            }
        }
        while (i > 0)
            scs.push_back(s1[i - 1]), i--;
        while (j > 0)
            scs.push_back(s2[j - 1]), j--;
        reverse(scs.begin(),scs.end());    
        return scs;
    }
};