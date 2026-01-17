class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int left_i   = bottomLeft[i][0];
            int bottom_i = bottomLeft[i][1];
            int right_i  = topRight[i][0];
            int top_i    = topRight[i][1];

            for (int j = i + 1; j < n; j++) {
                int left_j   = bottomLeft[j][0];
                int bottom_j = bottomLeft[j][1];
                int right_j  = topRight[j][0];
                int top_j    = topRight[j][1];
                
                //common intersection part
                int left   = max(left_i, left_j);
                int bottom = max(bottom_i, bottom_j);
                int right  = min(right_i, right_j);
                int top    = min(top_i, top_j);

                if(left < right && bottom < top){
                    int width  = right - left;
                    int height = top - bottom;

                    int side = min(width, height);
                    long long curr_area = 1LL*side*side;

                    ans = max(ans, curr_area);
                }
            }
        }
        return ans;
    }
};