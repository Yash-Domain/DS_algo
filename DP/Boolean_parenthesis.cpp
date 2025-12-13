// User function Template for C++
class Solution {
  public:
    int f(int i , int j , int isTrue , string &s , vector<vector<vector<int>>> &dp){
        if(i > j) return 0;
        if(i == j){
            if(isTrue == 1) {
                return s[i] == 'T';
            }
            else{
                return s[i] == 'F';
            }
        }
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        int ways = 0;
        for(int ind = i + 1 ; ind < j ; ind += 2){
            int lt = f(i , ind - 1 , 1 , s , dp);
            int rt = f(ind + 1 , j , 1 , s , dp);
            int lf = f(i , ind - 1 , 0 , s , dp);
            int rf = f(ind + 1 , j , 0 , s , dp);
            
            if(s[ind] == '&'){
               if(isTrue == 1) ways += lt * rt;
               else ways += lt*rf + lf*rt + lf*rf;
            }
            else if(s[ind] == '|'){
                if(isTrue == 1) ways += lt*rt + lf*rt + lt*rf;
                else ways += lf*rf;
            }
            else{
                if(isTrue == 1) ways += lf*rt + lt*rf;
                else ways += lt*rt + lf*rf;
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0,n-1,1,s,dp);
    }
};