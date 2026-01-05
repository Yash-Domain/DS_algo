class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;

        bool has_zero    = false;
        int  count_neg   = 0;
        int  min_abs_val = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num = matrix[i][j];

                if(num < 0){
                    count_neg++;
                }

                if (num == 0) {
                    has_zero = true;
                }

                sum += abs(num);

                min_abs_val = min(min_abs_val , abs(num));
            }
        }

        if(has_zero || count_neg % 2 == 0){
            return sum;
        }

        return sum - 2*min_abs_val;

    }
};