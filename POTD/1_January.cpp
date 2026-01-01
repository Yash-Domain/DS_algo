class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;

        ans = digits;

        int n = digits.size();

        if (digits[n - 1] != 9) {
            ans[n - 1] = ans[n - 1] + 1;
            return ans;
        }

        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += carry;
            if (ans[i] == 10) {
                ans[i] = 0;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        if (carry == 0)
            return ans;
        
        ans.insert(ans.begin(), 1);
        return ans;
    }
};