// A binary tree is considered height-balanced if the
// absolute difference in heights of the left and right subtrees
// is at most 1 for every node in the tree
class Solution {
public:
    int solve(TreeNode* root, int ht) {
        if (!root)
            return 0;

        int l = solve(root->left, ht + 1);
        if(l < 0) return l;

        int r = solve(root->right, ht + 1);
        if(r < 0) return r;

        if (abs(l - r) > 1)
            return -1e6;

        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        return solve(root, 0) >= 0 ? true : false;
    }
};