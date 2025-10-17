class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;

        for(auto a : asteroids){
            while(!st.empty() && st.top()>0 && a < 0){
                int sum = st.top() + a;
                if(sum < 0) st.pop();
                else if (sum > 0) a = 0; // for breaking and so not push in stack
                else{
                    a = 0; // both 
                    st.pop();
                }
            }
            if(a!=0) st.push(a);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
      }
};