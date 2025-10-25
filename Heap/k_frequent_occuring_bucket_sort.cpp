// O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }
        vector<vector<int>>bucket(n+1);

        for(auto i : mp){
            int freq = i.second;
            int val = i.first;

            bucket[freq].push_back(val);
        }

        vector<int> ans;
        for(int i = n ; i > 0 ; i--){
            
            if(bucket[i].size() == 0 ) continue;

            while(bucket[i].size() > 0 && k > 0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }

        }
        return ans;
    }
};