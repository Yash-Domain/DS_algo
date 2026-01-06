/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;
        int lvl = 0;
        q.push(root);
        int ans_lvl = 0;
        long long ans_sum = INT_MIN;

        while (!q.empty()) {
            lvl++;
            int size = q.size();
            long long sum = 0;
            

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            if (ans_sum < sum) {
                ans_sum = sum;
                ans_lvl = lvl;
            }
        }
        return ans_lvl;
    }
};