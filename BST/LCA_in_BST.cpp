// brute force 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == NULL || root == p || root == q ) return root;

        TreeNode* left = lowestCommonAncestor(root -> left,p ,q);
        TreeNode* right= lowestCommonAncestor(root -> right,p ,q);

        if(left && right) return root;
        else if(right) return right;
        return left;
    } 
};

// optimal using direction concept
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root -> val && q->val < root -> val)
            return lowestCommonAncestor(root -> left,p,q);
        if(p->val > root -> val && q->val > root -> val)
            return lowestCommonAncestor(root -> right,p,q);
        return root;
    }
};
