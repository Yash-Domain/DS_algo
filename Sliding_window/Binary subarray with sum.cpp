class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         int n = nums.size();
        int count = 0;
        int presum = 0;
        unordered_map<int ,int> mp;

        for(int i =0 ;i <n ;i++){
            presum += nums[i];
            if(presum == goal ) count ++;
            int rem = presum - goal;
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            
                mp[presum]++;
            
        }
        return count ;
    }
};