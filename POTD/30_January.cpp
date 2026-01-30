class Solution {
public:
    typedef long long ll;
    typedef pair<long long, string> p;
    ll t[1001];
    unordered_map<string, unordered_map<string,ll>> dijikCache;

    ll dijiktra(string &src, string &tar, unordered_map<string, vector<pair<string,int>>> &adj){

        if(dijikCache[src].count(tar))
            return dijikCache[src][tar];

        priority_queue<p, vector<p>, greater<p>> pq;
        unordered_map<string, ll> dist;
        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            auto[dis, curr_src] = pq.top();
            pq.pop();

            if(dis > dist[curr_src])
                continue;
            
            if(curr_src == tar) // reached 
                return dijikCache[src][tar] = dis;

            for(auto &it : adj[curr_src]){ 
                if(!dist.count(it.first) || dis + it.second < dist[it.first]){
                    dist[it.first] = dis + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }

        return dijikCache[src][tar] = 1e15; // unreached
    }

    ll solve (int ind, unordered_map<string, vector<pair<string,int>>> &adj,string &source, string &target, set<int> &st){
        if(ind >= source.size())
            return 0;
        
        if(t[ind] != -1)
            return t[ind];

        ll ans = 1e15;

        if(source[ind] == target[ind])
            ans = solve(ind + 1, adj, source, target, st);

        for(auto &i : st){
            if(ind + i > source.size())
                break;
            
            string src_sub = source.substr(ind, i);
            string tar_sub = target.substr(ind, i);

            if(!adj.count(src_sub))
                continue;

            // curr_ans ensures that the ans is valid or not 
            // using dijiktra if invalid it remains 1e15
            // so min of ans and curr_ans is 1e15 (in case of invalid)
            ll curr_ans = dijiktra(src_sub, tar_sub, adj); 

            if(curr_ans == 1e15)
                continue;
            
            ans = min(ans, curr_ans + solve(ind + i, adj, source, target, st));
        }

        return t[ind] = ans;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = original.size();
        unordered_map<string, vector<pair<string,int>>> adj;
        set<int>st;

        for(int i = 0; i < n; i++){
            string u = original[i];
            string v = changed[i];

            adj[u].push_back({v, cost[i]});

            st.insert(v.size());
        }

        memset(t, -1, sizeof(t));

        ll a = solve(0, adj, source, target, st); 

        return a > 1e14 ? -1 : a;
        
    }
};