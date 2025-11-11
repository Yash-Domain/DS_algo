// DFS
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &vis , vector<int>&pathvis, vector<int> &safe){
        vis[node] = 1 ;
        pathvis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
               if(dfs(it , adj , vis , pathvis, safe) == true)
                    return true;
            }
            else if (pathvis[it]) return true;
        }

        pathvis[node] = 0;
        safe[node] = 1;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>safe(n,0);

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i , adj , vis , pathvis , safe);
            }
        }
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if(safe[i] == 1){
            ans.push_back(i);
            }
        }
        return ans;
    }
};
//BFS
