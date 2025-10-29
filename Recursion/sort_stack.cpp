class Solution {
  public:
    void sortedInsertion(stack<int> &st, int ele){
        if(st.empty() || ele > st.top()) {
            st.push(ele);
            return;
        }
        int num = st.top();
        st.pop();
        
        sortedInsertion(st,ele);
        
        st.push(num);
    }
    
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        
        int ele = st.top();
        st.pop();
        
        sortStack(st);
        
        sortedInsertion(st,ele);
    }
};
