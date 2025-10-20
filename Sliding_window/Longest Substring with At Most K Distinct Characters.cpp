class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        
        set<int>st;
        for(auto i : s){
            st.insert(i);
        }
        if(st.size() < k) return -1;
        
        int n = s.size();
        int r = 0, l = 0;
        int maxlen = 0;
        unordered_map<char,int> mp;
        while(r < n){
            mp[s[r]]++;
            if(mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            if(mp.size() <= k){
                maxlen = max(maxlen , r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};