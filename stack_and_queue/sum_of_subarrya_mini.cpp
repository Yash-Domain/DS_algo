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

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int m = 1e9+7;
        vector<int> NSE = getNSE(arr,n);
        vector<int> PSE = getPSE(arr,n);
        int sum = 0;

        for(int i = 0 ; i < n ; i ++){
            int  lc = i - PSE[i];
            int  rc = NSE[i] - i ;

            long long totalcount = lc * rc;
            long long total_sum = arr[i]* totalcount;
            sum = (sum + total_sum) % m;

        }
        return sum;
    }
};