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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                } else {
                    ds.unionBySize(i, mp[mail]);
                }
            }
        }
        vector<vector<string>>mergedList(n);
        for (auto i : mp) {
            string word = i.first;
            int node = ds.findPar(i.second);
            mergedList[node].push_back(word);
        }
        vector<vector<string>>ans;
        for( int i = 0 ; i < n ; i++){
            if(mergedList[i].size() == 0) continue;
            sort(mergedList[i].begin() , mergedList[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(int k = 0 ; k < mergedList[i].size() ; k++){
                temp.push_back(mergedList[i][k]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};