class Solution {
public:
    int n;
    bool isPalindrome(int i , int j, string &s){
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int solve(int ind , string &s , vector<int>& dp){
        if(ind == n) return 0;
        if(dp[ind] != -1 ) return dp[ind];
        int ans = INT_MAX;
        for(int j = ind ; j < n ; j++){
            if(isPalindrome(ind,j,s)){
               int cost = 1 + solve(j+1,s,dp);
               ans = min(ans,cost);
            }
        }
        return dp[ind] = ans;
    }
    int minCut(string s) {
         n = s.length();
         vector<int>dp(n,-1);
         return solve(0,s,dp)-1;
    }
};