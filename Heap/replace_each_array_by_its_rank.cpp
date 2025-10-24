// User function Template for C++
// nlogn , sc = n;
class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
    vector<int>temp(arr.begin(),arr.end());
    sort(temp.begin(), temp.end());
    unordered_map<int,int> mp;
    int rank = 1;
    for(int i = 0 ; i < N ;i++ ){
        if(mp.find(temp[i]) == mp.end()){
             mp[temp[i]] = rank;
             rank++;
        }  
       
    }
        
        vector<int> ans;
        for(int i =0 ; i < N ;i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};
