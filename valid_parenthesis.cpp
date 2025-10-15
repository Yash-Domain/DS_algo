class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        int n = s.length();
        stack<char> st;
        for(int i = 0; i < n ; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.top=='(' && s[i]==')'
                || st.top=='{' && s[i]=='}'
                || st.top=='[' && s[i]==']' ){
                    st.pop();
                   
                }
            }
        }
        return st.size == 0 ;
    }
};