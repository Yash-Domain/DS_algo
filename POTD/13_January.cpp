// code written 
class Solution {
public:
    bool isValid(double y_ans, vector<vector<int>>& sq) {
        double upper_area = 0;
        double lower_area = 0;

        for (auto& y : sq) {
            double side = (y[1] - y[0]);

            if (y_ans < y[0]) {
                continue;
            }

            if (y_ans > y[1]) {
                lower_area += side * side ;
                continue;
            }

            lower_area += (y_ans - y[0]) * side;
        }

        for (auto& y : sq) {
            double side = (y[1] - y[0]);

            if (y_ans > y[1]) {
                continue;
            }

            if (y_ans < y[0]) {
                upper_area += side * side;
                continue;
            }

            upper_area += (y[1] - y_ans) * side;
        }

        return upper_area <= lower_area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();

        vector<vector<int>> sq;
        int min_lb = INT_MAX;
        int min_ub = INT_MIN;

        for (auto& i : squares) {
            int y_lb = i[1];
            min_lb = min(min_lb, y_lb);

            int y_ub = y_lb + i[2];
            min_ub = max(min_ub, y_ub);

            sq.push_back({y_lb, y_ub});
        }

        double l = min_lb;
        double r = min_ub;
        double ans = 0;

        while (r - l > 1e-6) {
            double mid = l + (r - l) / 2;
            if (isValid(mid, sq)) {
                ans = mid;
                r = mid;
            } else {
                l = mid;
            }
        }

        return ans;
    }
};

// optimised 
class Solution {
public:
    bool isValid(double y_ans, vector<vector<int>>& sq) {
        double diff = 0.0; // upper_area - lower_area

        for (auto& y : sq) {
            double bottom = y[0];
            double top = y[1];
            double side = top - bottom;

            if (y_ans <= bottom) {
                // entire square is above
                diff += side * side;
            } else if (y_ans >= top) {
                // entire square is below
                diff -= side * side;
            } else {
                // square is cut by the line
                diff += (top - y_ans) * side;    // upper part
                diff -= (y_ans - bottom) * side; // lower part
            }
        }

        return diff <= 0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();

        vector<vector<int>> sq;
        int min_lb = INT_MAX;
        int min_ub = INT_MIN;

        for (auto& i : squares) {
            int y_lb = i[1];
            min_lb = min(min_lb, y_lb);

            int y_ub = y_lb + i[2];
            min_ub = max(min_ub, y_ub);

            sq.push_back({y_lb, y_ub});
        }

        double l = min_lb;
        double r = min_ub;
        double ans = 0;

        while (r - l > 1e-6) {
            double mid = l + (r - l) / 2;
            if (isValid(mid, sq)) {
                ans = mid;
                r = mid;
            } else {
                l = mid;
            }
        }

        return ans;
    }
};