class Solution {
public:
    struct TrieNode {
        TrieNode* left;
        TrieNode* right;

        TrieNode() {
            left = NULL;
            right = NULL;
        }
    };

    void insert(TrieNode* root, int num) {
        TrieNode* crawler = root;

        for (int i = 31; i >= 0; i--) {
            int i_thBit = (num >> i) & 1;
            if (i_thBit == 0) {
                if (crawler->left == NULL) {
                    crawler->left = new TrieNode();
                }
                crawler = crawler->left;
            } else {
                if (crawler->right == NULL) {
                    crawler->right = new TrieNode();
                }
                crawler = crawler->right;
            }
        }
    }

    int findMaxXor(TrieNode* root, int num) {
        TrieNode* crawler = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int i_thBit = (num >> i) & 1;
            if (i_thBit == 1) {
                if (crawler->left != NULL) { // 1 ^ 0 != 0
                    maxXor += pow(2, i);     // ans add hora hai
                    crawler = crawler->left;
                } else {
                    crawler = crawler->right;
                }
            } else { // 0
                if (crawler->right != NULL) {
                    maxXor += pow(2, i); // different hai xor add
                    crawler = crawler->right;
                } else { // 0 ^ 0 = 0
                    crawler = crawler->left;
                }
            }
        }
        return maxXor;
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();

        for (int num : nums) {
            insert(root, num);
        }

        int ans = INT_MIN;

        for (int num : nums) {
            int currXor = findMaxXor(root, num);
            ans = max(ans, currXor);
        }
        return ans;
    }
};