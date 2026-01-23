// n log n
class Solution {
public:
    int minimumPairRemoval(vector<int>& temp) {
        vector<long long> nums(temp.begin(), temp.end());
        int n = nums.size();

        int bad_pairs = 0;
        set<pair<long long, int>> s;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                bad_pairs++;
            }
            s.insert({nums[i] + nums[i + 1], i});
        }

        vector<int> prev_ind(n), next_ind(n);
        for (int i = 0; i < n; i++) {
            prev_ind[i] = i - 1;
            next_ind[i] = i + 1;
        }

        int ops = 0;
        while (bad_pairs > 0) {
            auto [sum, ind] = *s.begin();
            // sum = nums[first] + nums[second];
            int first = ind;
            int second = next_ind[first];
            int first_left = prev_ind[first];
            int second_right = next_ind[second];

            s.erase(s.begin());

            if (nums[first] > nums[second]) {
                bad_pairs--;
            }

            if (first_left >= 0) {
                if (nums[first_left] <= nums[first] &&
                    nums[first_left] > sum) // GP -> BP
                    bad_pairs++;

                if (nums[first_left] > nums[first] &&
                    nums[first_left] <= sum) // BP => GP
                    bad_pairs--;
            }

            if (second_right < n) {
                if (nums[second] <= nums[second_right] &&
                    sum > nums[second_right]) // GP -> BP
                    bad_pairs++;

                if (nums[second] > nums[second_right] &&
                    sum <= nums[second_right]) // BP => GP
                    bad_pairs--;
            }

            if(first_left >= 0){
                s.erase({nums[first_left] + nums[first] , first_left});
                s.insert({nums[first_left] + sum, first_left});
            }

            if(second_right < n){
                s.erase({nums[second] + nums[second_right], second});
                s.insert({sum + nums[second_right], first});
                prev_ind[second_right] = first;
            }

            next_ind[first] = second_right;
            nums[first] += nums[second];
            ops++;
        }

        return ops;
    }
};