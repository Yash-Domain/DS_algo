class Solution {
public:
    typedef long long ll;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        multiset<ll> smaller;
        multiset<ll> larger;

        // intial window
        for (int i = 1; i <= 1 + dist; i++) {
            smaller.insert(nums[i]);
        }

        while (smaller.size() != (k - 1)) {
            auto it = smaller.end();
            int x = *prev(it);
            smaller.erase(prev(it));
            larger.insert(x);
        }

        ll f_ans;
        ll ans = 0;
        for (auto& it : smaller) {
            ans += it;
        }

        f_ans = ans;

        // travelling window
        for (int r = 2 + dist; r < n; r++) {
            int l = r - dist;

            ll out = nums[l - 1];
            ll in = nums[r];

            // out processing
            auto itLarge = larger.find(out);
            if (itLarge != larger.end()) {
                larger.erase(itLarge);
            } else {
                auto itSmall = smaller.find(out);
                smaller.erase(itSmall);
                ans -= out;

                if (!larger.empty()) {
                    smaller.insert(*larger.begin());
                    ans += *larger.begin();
                    larger.erase(larger.begin());
                }
            }

            // in processing
            int mxSmall = *smaller.rbegin();
            if (mxSmall > in) {
                smaller.erase(prev(smaller.end()));
                ans -= mxSmall;

                smaller.insert(in);
                ans += in;
                larger.insert(mxSmall);
            } else {
                larger.insert(in);
            }

            // last check if smaller is not k - 1 size
            if (smaller.size() < k - 1) {
                smaller.insert(*larger.begin());
                ans += *larger.begin();
                larger.erase(larger.begin());
            }

            f_ans = min(ans, f_ans);
        }

        return f_ans + nums[0];
    }
};