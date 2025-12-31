class Solution {
public:
    class TrieNode {
    public:
        int idx;
        int currlen;
        TrieNode* children[26];
        // constructor
        TrieNode() {
            idx = -1;
            currlen = INT_MAX;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
        // destructor
        ~TrieNode(){
            for( int i=0;i<26;i++){
                delete children[i];
            }
        }
    };

    void insert(string word, TrieNode* root, int i_ans) {
        TrieNode* crawler = root;

        for (int i = word.length() - 1; i >= 0; i--) {
            int ind = word[i] - 'a';
            if (crawler->children[ind] == NULL) {
                crawler->children[ind] = new TrieNode();
            }

            crawler =
                crawler->children[ind]; // root pe tha change kia children pe

            if (word.length() < crawler->currlen ||
                (word.length() == crawler->currlen && i_ans < crawler->idx)) {

                crawler->currlen = word.length();
                crawler->idx = i_ans;
            }
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        TrieNode* root = new TrieNode();

        int minilen = INT_MAX;
        int root_idx = 0;
        for (int i = 0; i < wordsContainer.size(); i++) {

            insert(wordsContainer[i], root, i);

            if (minilen > wordsContainer[i].size()) {
                minilen = wordsContainer[i].size();
                root_idx = i;
            }
        }
        root->idx = root_idx;
        //root->currlen = minilen;

        // part 2
        vector<int> ans;
        for (int i = 0; i < wordsQuery.size(); i++) {
            string word = wordsQuery[i];
            int final_ans = 0;
            TrieNode* crawler = root;

            for (int j = word.size() - 1; j >= 0; j--) {
                char ch = word[j];
                int ind = ch - 'a';
                if (crawler->children[ind] == NULL) {
                    final_ans = crawler -> idx;
                    break;
                }
                crawler = crawler->children[ind];

                final_ans = (crawler->idx);
            }

            ans.push_back(final_ans);
        }
        delete root;
        return ans;
    }
};
