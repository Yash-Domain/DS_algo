class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length() > n ) return "";
        int req_count = t.length();
        int start_i = 0;
        int minlen = INT_MAX;
        int l = 0 , r = 0;
        unordered_map<char,int> mp ;
        for(char ch : t){
            mp[ch]++;
        }
        while(r < n){
            char ch = s[r];
            if(mp[ch]>0) req_count -- ;
            mp[ch]--;
            while(req_count == 0){
                int len = r-l+1;
                if(len < minlen){
                    minlen = len;
                    start_i = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) req_count++;
                l++;
            }
            r++;
        }
        return minlen==INT_MAX ? "" : s.substr(start_i,minlen);
    }
};