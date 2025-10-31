class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(int row , int col , vector<string> &board){
        int drow = row;
        int dcol = col;

        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = drow , col = dcol;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = drow , col = dcol;
        while(row < board.size() && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(vector<string> &board, int col ,int n) {
        if(col == n){
            ans.push_back(board);
            return;
        }
        for( int row = 0 ; row < n ; row++){
            if(isValid(row,col,board)){
                board[row][col] = 'Q';
                solve(board,col+1,n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
       
        vector<string>board(n,string (n,'.'));
        solve(board,0,n);
        return ans;
    }
};