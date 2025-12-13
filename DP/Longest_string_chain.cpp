class Solution {
public:
    static bool mycomp(string &a , string &b){
        return a.size() < b.size();
    }

    bool isValid(string a, string b){ // isValid subsequence 
        if(a.size() != b.size() + 1) return false;
        int i = 0;
        int j = 0;
        while(i < a.size()){
            if(j < b.size() && a[i] == b[j]){
                j++;
            }
            i++;
        }
        return i == a.size() && j == b.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end() , mycomp);
        vector<int>dp(n,1);
        int maxi = -1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(isValid(words[i],words[j]) && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};