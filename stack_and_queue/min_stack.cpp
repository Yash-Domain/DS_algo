class MinStack {
public:

    stack<pair<int,int>> st;
    MinStack() {
        // domain 
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        int mini = min(val,st.top())
        st.push({val,mini};)
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        auto i = st.top();
        return i.first;
    }
    
    int getMin() {
        auto i = st.top();
        return i.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
