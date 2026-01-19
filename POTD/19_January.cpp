// brute force O(n^5)
class Solution {
public:
    bool isValid(int start_i, int start_j, int side, int threshold, vector<vector<int>>& mat){
        int sum = 0;
        for(int i = start_i; i < start_i + side; i++){
            for(int j = start_j; j < start_j + side; j++){
                sum += mat[i][j];
                if(sum > threshold)
                    return false;
            }
        }
        if(sum <= threshold)
            return true;
        
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        int side = min(n, m);

        for(int k = side; k >= 1; k--){
            for(int i = 0; i <= n - k; i++){
                for(int j = 0; j <= m - k; j++){
                    if(isValid(i, j, k, threshold, mat)){
                        return k;
                    }
                }
            }
        }

        return 0;
    }
};
// n^2logn
class Solution {
public:
    bool isValid(int start_i, int start_j, int side, int threshold, 
                vector<vector<int>>& mat, vector<vector<int>> &psum){

        int end_j = start_j + side - 1;
        int end_i = start_i + side - 1;

        int curr_sum = psum[end_i][end_j] 
                        - (start_j > 0 ? psum[end_i][start_j - 1] : 0)
                        - (start_i > 0 ? psum[start_i - 1][end_j] : 0)
                        + (start_i > 0 && start_j > 0 ? psum[start_i - 1][start_j - 1] : 0);
        
        if(curr_sum <= threshold)
            return true;
        
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>psum(n, vector<int>(m , 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               psum[i][j] = mat[i][j] 
                + (i > 0 ? psum[i - 1][j] : 0)
                + (j > 0 ? psum[i][j - 1] : 0) 
                - (i > 0 && j > 0 ? psum[i - 1][j - 1] : 0);
            }
        }

        int side = min(n, m);
        int l = 1, r = side;
        int ans = 0;
        while(l <= r){
            int mid = l + (r - l)/2;
            bool found = false;

            for(int i = 0; i <= n - mid; i++){
                for(int j = 0; j <= m - mid; j++){
                    if(isValid(i, j, mid, threshold, mat, psum)){
                        found = true;
                        break;
                    }
                }
            }

            if(found){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return ans;
    }
};