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

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin() , nums.end());
        int n = queries.size();

        vector<tuple<int,int,int>>q;
        for(int i = 0 ; i < n ; i++){
            q.push_back({queries[i][1],queries[i][0],i});
        }
        sort(q.begin(),q.end());

        TrieNode* root = new TrieNode();

        vector<int>ans(n);

        int j = 0;
        for(auto &i : q){
            auto [m_i,val,ind] = i;

            while(j < nums.size() && nums[j] <= m_i){
                insert(root,nums[j]);
                j++;
            }

            if(j == 0) ans[ind] = -1;
            else ans[ind] = findMaxXor(root,val);
        }
        return ans;
    }
};