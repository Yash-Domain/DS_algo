class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* curr = root;
        while(curr){
            if(curr -> left == NULL) curr = curr -> right;
            else{
                TreeNode* prev = curr -> left;
                while(prev -> right) prev = prev -> right;
                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
        }
    }
};

class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* curr = root;
        flatten(curr -> right);
        flatten(curr -> left);
        
        curr -> left = NULL;
        curr -> right = prev;
        prev = curr;
    } 
};