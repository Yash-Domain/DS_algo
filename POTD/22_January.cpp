class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;

        while(nums.size() > 1){
            int min_sum = INT_MAX;
            int min_ind = -1;

            if(is_sorted(nums.begin(), nums.end())){
                return cnt;
            }else{
                for(int i = 0; i < nums.size() - 1; i++){
                    if(min_sum > nums[i] + nums[i + 1]){
                        min_sum = nums[i] + nums[i + 1];
                        min_ind = i;
                    }
                }
                cnt++;
                nums[min_ind] = min_sum;
                nums.erase(nums.begin() + min_ind + 1);
            }
        }

        return cnt;
    }
};