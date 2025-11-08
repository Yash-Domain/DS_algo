class Solution {
public:
    int n , m;
    void dfs(int r , int c ,vector<vector<int>>& ans , int old_color ,int color){
        ans[r][c] = color;
        int drow[] = {-1 , 0 , 1 , 0};
        int dcol[] = {0 , 1 , 0 , -1};

        for(int i = 0 ; i < 4 ;i ++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 
               && ans[nrow][ncol] == old_color && ans[nrow][ncol] != color){
                dfs(nrow , ncol , ans , old_color, color);
               }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         n = image.size();
         m = image[0].size();
        int old_color = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs( sr , sc , ans , old_color , color);

        return ans;
    }
};