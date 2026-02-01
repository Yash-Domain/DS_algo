class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < m1){
                m2 = m1; // m2 is second min of all
                m1 = nums[i];
            }else if(nums[i] < m2){ // [11 5 2 2]
                m2 = nums[i];
            }
        }

        return nums[0] + m1 + m2;
    }
};