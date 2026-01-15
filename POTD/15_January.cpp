class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        int h_cnt = 1;
        int curr_cnt1 = 1;
        int v_cnt = 1;
        int curr_cnt2 = 1;

        for (int i = 0; i < h.size() - 1; i++) {
         
            if (h[i] + 1 == h[i + 1]) {
                curr_cnt1++;
            } else {
                curr_cnt1 = 1;
            }

            h_cnt = max(h_cnt, curr_cnt1);
        }

        for (int i = 0; i < v.size() - 1; i++) {
        
            if (v[i] + 1 == v[i + 1]) {
                curr_cnt2++;
            } else {
                curr_cnt2 = 1;
            }

            v_cnt = max(v_cnt, curr_cnt2);
        }

        int side = min(h_cnt, v_cnt) + 1;

        return side * side;
    }
};