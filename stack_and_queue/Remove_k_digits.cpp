class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && k > 0 && 
            ((st.top()-'0') > (num[i]-'0'))){
            st.pop();
            k--;
            }
            st.push(num[i]);
            }
        while(k > 0) { // if k remains pop out the last digits 
            st.pop();  // stack remains monotonic throughout
            k--;
        }
        if(st.empty()) { // k == n
            return "0";
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        while(res.size()>0 && res.back() == '0'){ // remove starting zeros
            res.pop_back();
        }
        if(res.size() == 0 ) return "0"; // "000000"
        reverse(res.begin(), res.end());
        return res;
    }
};