// optimal 
class Solution {
public:
    int ans_sum = 0;
    void calculate_ans_sum(int n) {
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ans_sum += i;
                if (i != n / i) {
                    ans_sum += n / i;
                }
            }
        }
    }
    bool has_4_divisor(int n) {
        int cnt = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cnt++;
                if (i != n / i) {
                    cnt++;
                }
            }

            if (cnt > 4) {
                return false;
            }
        }
        return cnt == 4;
    }

    int sumFourDivisors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (has_4_divisor(nums[i])) {
                calculate_ans_sum(nums[i]);
            }
        }
        return ans_sum;
    }
};
// two function to one function 
class Solution {
public:
    int has_4_divisor(int n) {
        int cnt = 0;
        int sum = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cnt++;
                sum += i;
                if (i != n / i) {
                    cnt++;
                    sum += n/i;
                }
            }

            if (cnt > 4) {
                return 0;
            }
        }
        return (cnt == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans_sum += has_4_divisor(nums[i]);
        }
        return ans_sum;
    }
};