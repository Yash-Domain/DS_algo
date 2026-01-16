class Solution {
public:
    int const mod = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        h.push_back(m);

        v.push_back(1);
        v.push_back(n);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        unordered_set<int> st;

        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                int num_to_insert = v[j] - v[i];
                st.insert(num_to_insert);
            }
        }

        long long ans = -1;

        for (int i = 0; i < h.size(); i++) {
            for (int j = i + 1; j < h.size(); j++) {
                int it1 = h[j] - h[i];
                if(st.count(it1)){
                    long long curr_area = (1LL * it1 * it1);
                    ans = max(ans, curr_area);
                }
            }
        }

        return ans % mod;
    }
};