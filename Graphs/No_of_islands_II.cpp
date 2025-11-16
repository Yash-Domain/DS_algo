// User function Template for C++
class DisjointSet{
    vector<int> size, parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0 ; i <= n ; i++){
            parent [i] = i;
        }
    }
    int findPar (int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = findPar(parent[u]);
    }
    void unionBySize(int u , int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>ans;
        int cnt = 0;
        DisjointSet ds(n*m); // storing each node of matrix in ds 
        for(auto i : operators){
            int r = i[0];
            int c = i[1];
            if(vis[r][c] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[r][c] = 1;
            cnt++;
            
            int drow[] = {-1 , 0 , 1 , 0};
            int dcol[] = {0 , -1 , 0 , 1};
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                    if(vis[nrow][ncol] == 1){
                        int prev_ds = r * m + c; 
                        int new_ds  = nrow * m + ncol;
                        if(ds.findPar(prev_ds) != ds.findPar(new_ds)){
                            cnt--;
                            ds.unionBySize(prev_ds,new_ds);
                        }
                    }
                }
            }
            ans.push_back(cnt); // checked all the 4 direction
        }
        return ans;
    }
};
