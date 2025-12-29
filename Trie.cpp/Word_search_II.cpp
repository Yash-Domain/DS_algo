class Solution {
public:
    class TrieNode{
        public:
        bool isEndofWord;
        TrieNode* children[26];
        string word;

        TrieNode(){
            isEndofWord = false;
            word = "";
            for(int i = 0 ; i < 26 ; i++){
                children[i] = NULL;
            }
        }
    };

    void insert(string word,TrieNode* root){
        TrieNode* crawler = root;
        for(int i = 0 ; i < word.length() ; i++){
            int ind = word[i] - 'a';
            if(crawler -> children[ind] == NULL){
                crawler -> children[ind] = new TrieNode();
            }
            crawler = crawler -> children[ind];
        }
        crawler -> isEndofWord = true;
        crawler -> word = word;
    }

    vector<string> ans;
    int n , m;
    void dfsfind(vector<vector<char>>& board , int r , int c , TrieNode* root){
        if(r < 0 || r >= n || c < 0 || c >= m ){
            return;
        }
        if(board[r][c] == '$' || root -> children[board[r][c] - 'a'] == NULL){
            return;
        }

        root = root -> children[board[r][c] -'a'];

        if(root -> isEndofWord == true){
            ans.push_back(root -> word);
            root -> isEndofWord = false;  // one more word possible at down
        }

        int drow[] = {-1 , 0 , 1 , 0};
        int dcol[] = {0 , -1 , 0 , 1};

        char temp = board[r][c] ;
        board[r][c] = '$';
        for(int i = 0 ; i < 4 ; i++){
            int nrow = r + drow[i]; 
            int ncol = c + dcol[i];
                dfsfind(board,nrow,ncol,root);

        }
        board[r][c] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         n = board.size();
         m = board[0].size();

        TrieNode* root = new TrieNode();

        for(string word : words){
            insert(word,root);
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                char ch = board[i][j];
                if(root -> children[ch-'a'] != NULL){
                    dfsfind(board,i,j,root);
                }
            }
        }
        return ans;
    }
};