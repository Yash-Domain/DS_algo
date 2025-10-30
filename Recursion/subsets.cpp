class Solution {
public:
    //vector<vector<int>> ans;
    void solve (vector<int>& nums , int ind , int n , vector<int> temp , vector<vector<int>> &ans){
        if(ind >= n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        solve(nums , ind + 1 , n , temp , ans);

        temp.pop_back();
        
        solve(nums , ind + 1 , n , temp , ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp ;
        int n = nums.size();
        solve(nums,0,n,temp,ans);
        return ans;
    }
};