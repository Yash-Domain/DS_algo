class DisjointSet{
    vector<int>size, parent;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
    }
    int findPar(int u){
        if(parent[u] == u )
            return u;
        return parent[u] = findPar(parent[u]);
    }
    void uniounBySize(int u , int v){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int nC = 0;
        int extraEdges = 0;
        for(auto i : connections){
            int u = i[0];
            int v = i[1];
            if(ds.findPar(u) != ds.findPar(v)){
                ds.uniounBySize(u,v);
            }
            else{
                extraEdges++;
            }
        }
        for(int i = 0 ; i < n ; i++){ // need to find after complete unioun  
            if(ds.findPar(i) == i) nC++;
        }
        if(extraEdges >= nC - 1) return nC -1;
        return -1;
    }
};