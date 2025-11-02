/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        ht(root);
        return maxi;
    }
    int ht(TreeNode* root){
        if(!root) return 0;
        int lh = ht(root -> left);
        int rh = ht(root -> right);
        maxi = max(maxi , lh + rh);
        return 1 + max(lh , rh) ;
    }
};