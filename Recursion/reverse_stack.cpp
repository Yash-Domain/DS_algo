class Solution {
  public:
    void insertAtBottom(stack<int> &st , int ele){
        if(st.empty()) {
            st.push(ele);
            return ;
            }
        
        int num = st.top();
        st.pop();
        insertAtBottom(st,ele);
        st.push(num);
    }
  
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int num = st.top(); 
        st.pop();
        
        reverseStack(st);
        insertAtBottom(st, num);
    }
};