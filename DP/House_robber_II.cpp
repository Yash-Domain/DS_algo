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
        if(n==1) return nums[0];  

        vector<int>temp1,temp2;
        for(int i = 0 ; i < n ; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        memset(t,-1,sizeof(t));
        int a = solve(temp1,n-2);

        memset(t,-1,sizeof(t));
        int b = solve(temp2,n-2);

        return max(a,b);
    }
};