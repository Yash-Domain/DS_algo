class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int hash[256] = {0};
        int l =0, r =0;
        int maxlen = 0;
        while(r<n){
            if(hash[s[r]] != 0){ // in the map
               l = max(l,hash[s[r]]);
            }
            int len = r-l+1;
            maxlen = max(len,maxlen);
            hash[s[r]] = r+1;
            r++;
        }
        return maxlen;
    }
};