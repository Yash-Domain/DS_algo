class Solution {
  public:
    void solve(vector<int>& arr, vector<int> &ans,int ind, int n ,int sum){
        if(ind == n){
            ans.push_back(sum);
            return;
        }
        //include
        solve(arr,ans,ind+1,n ,sum + arr[ind]);
        //exclude 
        solve(arr,ans,ind+1,n,sum);
    }
  
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n = arr.size();
        //vector<int> temp;
        vector<int> ans;
        solve(arr,ans,0,n,0);
        return ans;
    }
};