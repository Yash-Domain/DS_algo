class Solution {
public:
    bool check(TreeNode* p , TreeNode* q){
        if(!p || !q) return p == q ;
        return p -> val == q -> val && check(p -> left , q -> right) 
                    && check(p -> right, q -> left);
    }

    bool isSymmetric(TreeNode* root) {
       if(!root) return true;
       return check(root -> left , root -> right);
        
    }
};