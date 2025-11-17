//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int>&st){
        vis[node] = 1;
        for(int it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    void dfs2(int node, vector<vector<int>> &adjT, vector<int> &vis){
        vis[node] = 1;
        for(int it : adjT[node]){
            if(!vis[it]){
                dfs2(it,adjT,vis);
            }
        }
    } 
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>vis(n,0);
        stack<int>st;
        for(int i = 0 ; i < n ;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<vector<int>> adjT(n);
        for(int i = 0 ; i < n ; i++){
            for(auto it : adj[i]){
                adjT[it].push_back(i);
            }
        }
        vis.clear();
        int m = adjT.size();
        vis.resize(m,0);
        int cnt = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                cnt++;
                dfs2(node,adjT,vis);
            }
        }
        return cnt;
    }
};