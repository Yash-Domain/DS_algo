class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        //sliding window reverse logic
        int l = 0, r = 0;
        int max_len = 1;
        while(r < n && l < n){
            if(1LL* nums[l] * k >= nums[r]){
                max_len = max(max_len, r - l + 1);
                r++;
            }else{
                l++;
            }
        }

        return n - max_len;
    }
};