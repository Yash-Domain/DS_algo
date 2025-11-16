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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0 , maxcol = 0;
        for(auto i : stones){
            maxrow = max(maxrow,i[0]);
            maxcol = max(maxcol,i[1]);
        }
        DisjointSet ds(maxrow + maxcol + 1);
        unordered_map<int,int>mp;
        for(auto i : stones){
            int rownode = i[0];
            int colnode = i[1] + maxrow + 1;
            ds.unionBySize(rownode,colnode);
            mp[rownode] = 1 ;
            mp[colnode] = 1;
        }
        int nC = 0;
        for(auto i : mp){
            if(ds.findPar(i.first) == i.first){
                nC++;
            }   
        }
        return stones.size() - nC;
    }
};
