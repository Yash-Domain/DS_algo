// Brute force 

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