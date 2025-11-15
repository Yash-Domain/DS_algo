// User function Template for C++
class DisjointSet{
    vector<int> rank , parent , size;
    public:
    // constructor
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int node){ //findpar == leader 
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u , int v){ // union 
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u  == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{ // same 
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u ,int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u  == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        int ans = 0;
        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });

        DisjointSet ds(V);
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            if(ds.findPar(u) != ds.findPar(v)){
                ans += wt;
                ds.unionByRank(u,v);
            }
        }
        return ans;
    }
};