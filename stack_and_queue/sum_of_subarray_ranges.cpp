class Solution {
public:
    vector<int> getPSE(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getNSE(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getPGE(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getNGE(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> PSE = getPSE(nums,n);
        vector<int> NSE = getNSE(nums,n);
        vector<int> PGE = getPGE(nums,n);
        vector<int> NGE = getNGE(nums,n);
        long long sumMin = 0;
        long long sumMax = 0;

        for(int i = 0 ; i < n ; i++){
            long long lsc = i - PSE[i];
            long long  rsc = NSE[i] - i;
            long long  totalcount = lsc*rsc;
            long long totalsum = nums[i]* totalcount;
            sumMin += totalsum;
        }
        for(int i = 0 ; i < n ; i++){
            long long lsc = i - PGE[i];
            long long  rsc = NGE[i] - i;
            long long  totalcount = lsc*rsc;
            long long totalsum = nums[i]* totalcount;
            sumMax += totalsum;
        }
        return (sumMax - sumMin);
    }
};