class Solution {
public:
    int solve(int i , int j ,string &word1 , string &word2 , vector<vector<int>>&dp){
        if(i < 0) return j+1; // insert operation 
        if(j < 0) return i+1; // delete 
        if(dp[i][j] != -1) return dp[i][j];
        // match making 
        if(word1[i] == word2[j]){ // same hai no operation needed 
            return dp[i][j] = 0 + solve(i-1,j-1,word1,word2,dp);
        }
        return dp[i][j] = 1 + min(solve(i-1,j-1,word1,word2,dp),   // replace, insert, delete
        min(solve(i,j-1,word1,word2,dp),solve(i-1,j,word1,word2,dp)));

    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,word1,word2,dp);
    }
};