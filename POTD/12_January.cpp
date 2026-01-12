class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();

        for(int i = 0 ; i < n -1 ; i++){
            auto curr = points[i];
            auto next = points[i + 1];

            int curr_x = curr[0];
            int curr_y = curr[1];

            int next_x = next[0];
            int next_y = next[1];

            int to_add = max(abs(next_x - curr_x),abs(next_y - curr_y));

            ans += to_add;
        }
        return ans;
    }
};