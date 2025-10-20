class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> temp;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] % 2 == 0){
                temp.push_back(0);
            }
            else{
                temp.push_back(1);
            }
        }
        int presum=0;
        for(int i = 0 ; i < n ; i++){
            presum += temp[i];
            if(presum==k) count++;
            int rem = presum - k ;
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            mp[presum]++;
        }
        return count ;
    }
};