class Trie {
public:
    class TrieNode{ // 
        public:
        bool isEndofWord ;
        TrieNode* children[26];
    };

    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode();
        newNode -> isEndofWord = false;
        for(int i = 0 ; i < 26 ; i++){
            newNode -> children[i] = NULL;
        }
        return newNode;
    }

    TrieNode* root = getNode();

    Trie() {

    }
    
    void insert(string word) {
        TrieNode* crawler = root;
        for(int i = 0 ; i < word.length() ; i++){
            int ind = word[i] - 'a';
            if(crawler -> children[ind] == NULL){
                crawler -> children[ind] = getNode();
            }
            crawler = crawler -> children[ind];
        }
        crawler -> isEndofWord = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;
        for(int i = 0 ; i < word.length() ; i++){
            int ind = word[i] - 'a';
            if(crawler -> children[ind] == NULL){
                return false;
            }
            crawler = crawler -> children[ind];
        }
        return crawler -> isEndofWord == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;
        int i = 0 ;
        for(; i < prefix.length() ; i++){
            int ind = prefix[i] - 'a';
            if(crawler -> children[ind] == NULL){
                return false;
            }
            crawler = crawler -> children[ind];
        }
        return i == prefix.length();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */