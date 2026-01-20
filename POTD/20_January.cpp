class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans(n);

        for(int i = 0; i < n; i++){
            int num = nums[i];
            int k = 0;
            for(; k < num ; k++){
                int a = k | (k + 1);
                if(a == num){
                    ans[i] = k;
                    break;
                }
            }
            
            if(k == num){
                ans[i] = -1;
            }
        }

        return ans;
    }
};