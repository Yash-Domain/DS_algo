// User function Template for C++

class Solution {
  public:
    int m = 1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int>vis(100000,0);
        queue<pair<int,int>>q;
        q.push({start,0});
        vis[start] = 0 ;
        while(!q.empty()){
            auto [num , step] = q.front();
            q.pop();
            if(num == end) return step;
            for(int i = 0 ; i < arr.size() ; i++){
                int mul = (num * arr[i]) % m;
                if(!vis[mul]){
                    vis[mul] = 1;
                    q.push({mul,step+1});
                }
            }
        }
        return -1;
    }
};
