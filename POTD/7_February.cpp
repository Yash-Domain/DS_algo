class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        //You need to find for every index the number of b's before it 
        //and the number of a's after it
        //and the min sum of that index is ans 
        vector<int> prefix_b(n), suffix_a(n);

        prefix_b[0] = s[0] == 'b' ? 1 : 0;
        suffix_a[n - 1] = s[n - 1] == 'a' ? 1 : 0;

        for (int i = 1; i < n; i++) {
            prefix_b[i] = s[i] == 'b' ? 1 + prefix_b[i - 1] : prefix_b[i - 1];
        }

        for(int i = n - 2; i >= 0; i--){
            suffix_a[i] = s[i] == 'a' ? 1 + suffix_a[i + 1] : suffix_a[i + 1];
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, prefix_b[i] + suffix_a[i]);
        }

        // why -1 because we are double counting at that idx
        return ans > 0 ? ans - 1 : 0 ;
    }
};