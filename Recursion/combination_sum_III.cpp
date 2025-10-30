class Solution {
public:
    vector<vector<int>> ans;
    void solve(int k , int n, int ind ,vector<int> &temp ){
        if(temp.size() == k){
            if(n== 0){
            ans.push_back(temp);
            }
            return;
        }
        for(int i = ind ; i <= 9 ; i++ ){
            if(i > n) break;
            temp.push_back(i);
            solve(k,n-i,i+1,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(k,n,1,temp);
        return ans;
    }
};