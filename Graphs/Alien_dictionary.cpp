class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_set<char>s;
        vector<vector<int>>adj(26);
        for(int i = 0 ; i < words.size() ; i++){
            string count = words[i];
            for(int j = 0 ; j < count.length();j++){
                s.insert(count[j]);
            }
        }
        for(int i =0 ; i  < words.size() - 1 ; i++){
            string first = words[i];
            string second = words[i+1];
            int j = 0;
            int len = min(first.length(),second.length());
            for(; j < len ;j++){
                if(first[j] != second[j]){
                    adj[first[j]-'a'].push_back(second[j]-'a');
                    break;
                }
            }
            if(j == len  && first.size() > second.size()) return ""; // edge case
        }
        int V = s.size();
        vector<int>indegree(26,0);
        for(int i = 0 ; i < 26 ; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i = 0 ; i < 26 ; i++){
            if(s.count('a' + i) && indegree[i] == 0) q.push(i);
        }
        string topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back('a' + node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == V) return topo;
        return "";
    }
};