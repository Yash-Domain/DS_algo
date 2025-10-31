class Solution {
public:
    int m , n;
    bool find(int i , int j ,vector<vector<char>>& board, string &word , int ind){
    int di[] = {0,-1,0,1};
    int dj[] = {1,0,-1,0};
        if(ind == word.length()) return true ;
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$' ) return false;
        if(board[i][j] != word[ind]) return false ;

        char temp = board[i][j];
        board[i][j] = '$';

        for(int k = 0 ; k < 4 ; k++){
            int new_i = i + di[k];
            int new_j = j + dj[k];
            if(find(new_i , new_j , board , word , ind + 1)){
                board[i][j] = temp;
                return true;
            }
        }
        board[i][j] = temp;
        return false ;

    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++ ){
                if(board[i][j] == word[0] && find(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};