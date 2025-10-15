class Solution {
  public:
    int priority(char s){
        if(s=='^') return 3;
        if(s=='*' || s=='/') return 2;
        if(s=='+' || s== '-') return 1;
        return 0;
    }
    
    string infixToPostfix(string& s) {
        // code here
        stack<char>st;
        int i = 0;
        string ans="";
        while(i<s.length()){
            if(s[i] >= 'A' && s[i] <= 'Z' || 
            s[i] >= 'a' && s[i] <= 'z' ||
            s[i] >= '0' && s[i] <= '9'){
                ans += s[i];
            }
            else if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                   while(!st.empty() && 
                      ((priority(s[i]) < priority(st.top())) || 
                       (priority(s[i]) == priority(st.top()) && s[i] != '^'))){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
                i++;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
