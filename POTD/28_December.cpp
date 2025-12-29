// brute n*m
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt= 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] < 0){
                    cnt += m - j;
                    break;
                }
            }
        }
        return cnt ;
    }
};
// better nlogm
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt= 0;

        for(auto &row : grid){
            int ind = upper_bound(row.begin(),row.end(),0,greater<int>()) - row.begin();
            cnt += m - ind;
        }
        return cnt ;
    }
};

//optimal n+m
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt= 0;

        int row = n-1 , col = 0 ;

        while(row >= 0 && col < m){
            if(grid[row][col] >= 0){
                col++;
            }else{
                cnt += m - col;
                row-- ;
            }
        }
        return cnt ;
    }
};
