// Brute force  O(N*N)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0 ; i < nums1.size() ; i++){
            int ele = nums1[i];
            int max_ele = -1;
            for(int j = 0 ; j < nums2.size() ; j++){
                if(ele == nums2[j]){
                    for(int k = j+1 ; k < nums2.size() ; k++){
                        if(nums2[k] > nums2[j]){
                            max_ele = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
            ans.push_back(max_ele);
        }
        return ans; 
    }
};

// optimal using stack // O(N)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        stack<int> st;

        for(int i = nums2.size() -1 ; i>=0 ; i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }
            if(st.empty()) mp[nums2[i]] = -1 ;
            else mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for(int i = 0 ; i < nums1.size() ; i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};