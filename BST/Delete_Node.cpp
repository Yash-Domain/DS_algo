class Solution {
public:
    TreeNode* getIS(TreeNode* root) {
        while (root && root->left) {
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else { // key == root // 0 / 1 child dono cover
            if (root->left == NULL) {
                TreeNode* temp = root->right; // 0 child mein null hoga
                delete (root);
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete (root);
                return temp;
            } else { // dono not null  // 2 child
                TreeNode* IS = getIS(root->right);
                root->val = IS->val;
                root->right = deleteNode(root->right, IS->val);
            }
        }
        return root;
    }
};