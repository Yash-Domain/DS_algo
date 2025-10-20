class Solution {
public:
    int helper(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0, r = 0, count = 0;
        unordered_map<int, int> mp;

        while (r < n) {
            mp[nums[r]]++;

            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
           if(mp.size() <= k) count += r-l+1 ; 
           r++;    // solving for at most k distnct numbers     
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};