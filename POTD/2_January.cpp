// brute 
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int N = nums.size();
        int n = N/2;

        unordered_map<int,int>mp;

        for(int &i : nums){
            mp[i]++;
        }

        for(auto &i : mp){
            if(i.second == n){
                return i.first;
            }
        }

        return 0;
    }
};

// approach 2 
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int N = nums.size();

        for(int i = 2 ; i < N ; i++){
            if(nums[i] == nums[i-1] || nums[i] == nums[i-2]){
                return nums[i];
            }
        }
        return nums.back();
    }
};