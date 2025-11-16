class DisjointSet{
    public:
    vector<int> size, parent;
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
    int largestIsland(vector<vector<int>>& grid) {
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    for (int i = 0; i < 4; i++) {
                        int nrow = r + drow[i];
                        int ncol = c + dcol[i];
                        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n) {
                            if (grid[nrow][ncol] == 1) {
                                int node = r * n + c;
                                int new_node = nrow * n + ncol;
                                if (ds.findPar(node) != ds.findPar(new_node)) {
                                    ds.unionBySize(node, new_node);
                                }
                            }
                        }
                    }
                }
            }
        }
        int mx = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    set<int>st;
                    for (int i = 0; i < 4; i++) {
                        int nrow = r + drow[i];
                        int ncol = c + dcol[i];
                        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n) {
                            if (grid[nrow][ncol] == 1) {
                                int new_node = nrow * n + ncol;
                                st.insert(ds.findPar(new_node));
                            }
                        }
                    }
                    int total_size = 1;
                    for(auto i : st){
                        total_size += ds.size[i];
                    }
                mx = max(mx, total_size);
                }
            }
        }
        mx = max(mx, ds.size[0]);
        return mx;
    }
};