class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> doublee;
        stack<int> st;
        vector<int> ans(2*nums.size(),0);
        vector<int> fans;
        for(int i = 0 ; i < nums.size() ; i++){
            doublee.push_back(nums[i]);
        }
        for(int i = 0 ; i < nums.size() ; i++){
            doublee.push_back(nums[i]);
        }
        for(int i = doublee.size()-1 ; i >= 0 ; i--){
            while(!st.empty() && doublee[i] >= st.top()){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(doublee[i]);
        } 
        for(int i = 0 ; i < nums.size() ; i++){
            fans.push_back(ans[i]);
        }
        return fans;
    }
};