class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxlen = 0;
        int l = 0 , r=0;
        map<int,int> mp;
        while(r<n){
            mp[arr[r]]++;
            if(mp.size() > 2){
                mp[arr[l]]--;
                if(mp[arr[l]]==0) mp.erase(arr[l]);
                l++;
            }
            if(mp.size() <= 2){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};