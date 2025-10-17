// brute force 
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        unordered_map<int,int> mp;
        vector<int> temp;
        sort(arr.begin() , arr.end());
        for(int i = 0 ; i< arr.size() ; i++){
            mp[arr[i]] = arr.size()-i-2;
        }
        for(int i=0 ; i < indices.size() ; i++){
            temp.push_back(mp[arr[indices[i]]]);
        }
        return temp;
    }
};

//optimal
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        stack<pair<int,int>> st;
        vector<int> ans(arr.size(),0);
        vector<int> fans;
        int count = 0;
        for(int i = arr.size()-1 ; i >= 0 ; i--){
            
            while(!st.empty() && arr[i] <= st.top().first){
                //count = st.top().second;
                st.pop();
                count++;
            }
            ans[i] = count;
            st.push({arr[i],count});
        }
        for(int i = 0 ; i < indices.size() ; i++){
            fans.push_back(ans[indices[i]]);
        }
        return fans;
    }
};