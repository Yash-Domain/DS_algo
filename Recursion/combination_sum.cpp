class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& candidates , int target , int ind , vector<int> temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;
        if(ind == candidates.size()) return;
        //include
        temp.push_back(candidates[ind]);
        solve(candidates,target-candidates[ind],ind,temp);
        temp.pop_back();
        //exclude 
        solve(candidates,target,ind + 1,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates,target,0,temp);
        return ans;
    }
};