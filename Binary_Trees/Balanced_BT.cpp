class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(ht(root) == -1) return false;
        return true;
    }
    int ht(TreeNode* root){
        if(root == NULL) return 0;

        int lh = ht(root -> left);
        if(lh == -1) return -1 ;
        int rh = ht(root -> right);
        if(rh == -1) return -1 ; 

        if(abs(lh - rh) > 1) return -1 ;
        return 1 + max(lh,rh);
        
    }
};