class Solution {
public:
    TreeNode* tree(int s, int e, vector<int> &inorder){
        if(s > e)
            return NULL;
        
        //leaf node
        if(s == e)
            return new TreeNode(inorder[s]);

        int mid = (s + e + 1)/2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root -> left  = tree(s, mid - 1, inorder);
        root -> right = tree(mid + 1, e, inorder);

        return root;
    }

    void inOrder(TreeNode* root, vector<int> &inorder) {
        if (!root)
            return;

        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }

    TreeNode* balanceBST(TreeNode* root) { 
        vector<int> inorder;
        inOrder(root, inorder); 
        return tree(0, inorder.size() - 1, inorder);
    }
};