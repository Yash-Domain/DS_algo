class Solution {
public:
    TreeNode* prev  = NULL;
    TreeNode* first = NULL;
    TreeNode* second= NULL;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root -> left);
        if(prev && root -> val < prev -> val ){
            if(!first) first = prev;
            second = root;
        }
        prev = root;
        inorder(root -> right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = first -> val;
        first -> val = second -> val;
        second -> val  = temp;
    }
};