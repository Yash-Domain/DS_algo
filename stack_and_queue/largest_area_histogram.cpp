class Solution {
public:
    vector<int> getNSE(vector<int> arr, int n){
        vector<int> ans(n,0);
        stack<int> st;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getPSE(vector<int> arr, int n){
        vector<int> ans(n,0);
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSE = getNSE(heights,n);
        vector<int> PSE = getPSE(heights,n);
        int ans = 0;
        for(int i=0 ; i < n; i++){
            int area = heights[i] * (NSE[i]-PSE[i]-1);
            ans = max(ans,area);
        }
        return ans;

    }
};