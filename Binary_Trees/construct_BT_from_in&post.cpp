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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return solve(inorder, postorder, 0, n - 1, 0, n - 1, mp);
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart,
                    int inEnd, int postStart, int postEnd,
                    unordered_map<int, int>& mp) {
        if (inStart > inEnd || postStart > postEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mp[root -> val];
        int leftnums = inRoot - inStart;
        root -> left = solve(inorder , postorder , inStart , inRoot - 1 , postStart , postStart + leftnums - 1 ,mp);
        root -> right= solve(inorder , postorder , inRoot + 1 , inEnd , postStart + leftnums  , postEnd - 1,mp);
        return root ; 
    }
};