class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;

        for(int i = 0; i < n; i++){
            if(nums[i] == 2){
                ans.push_back(-1);
                continue;
            }

            int prev = -1;
            for(int j = 0; j < 32; j++){
                //check setbit present
                if(((nums[i] >> j) & 1) != 1){
                    prev = j - 1;
                    break;
                }
            }

            if(prev != -1){
                int to_xor = (1 << prev);
                int num = nums[i] ^ to_xor;
                ans.push_back(num);
            }else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};