class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(), a.end(),greater<int>());
        sort(b.begin(), b.end(),greater<int>());
        
        priority_queue<tuple<int,int,int>> pq; // val , i , j
        set<pair<int,int>> s;
        
        pq.push({a[0]+b[0],0,0});
        s.insert({0,0});
        
        vector<int> ans;
        
        while(k-- && !pq.empty()){
            auto [sum,i,j] = pq.top();
            pq.pop();
            ans.push_back(sum);
            
            if(i+1 < a.size() && !s.count({i+1,j})){
                pq.push({a[i+1]+b[j],i+1,j});
                s.insert({i+1,j});
            }
            if(j+1 < b.size() && !s.count({i,j+1})){
                pq.push({a[i]+b[j+1],i,j+1});
                s.insert({i,j+1});
            }
        }
        return ans;
    }
}; 