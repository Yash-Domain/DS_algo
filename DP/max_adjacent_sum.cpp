class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int ind){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(t[ind] != -1) return t[ind];
        int skip = 0 + solve(nums,ind-1); // not picked not added and can move 
                                            // one index back because not picked 

        int pick = nums[ind] + solve(nums,ind-2); // pick kiya add hogya


        return t[ind] = max(pick,skip);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,n-1);
    }
};