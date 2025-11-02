class Solution {
public:
    int maxi = INT_MIN;
    int maxSum(TreeNode* root){
        if(!root) return 0;
        int lsum = max(0, maxSum(root -> left));
        int rsum = max(0, maxSum(root -> right));
        maxi = max(maxi , root -> val + lsum + rsum) ;
        return root -> val + max(lsum , rsum);
    }

    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return maxi;
    }
};