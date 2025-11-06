class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return Build(preorder,i,INT_MAX);
    }
    TreeNode* Build(vector<int>& preorder,int &i,int UB){
        if(i==preorder.size() || preorder[i] > UB) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root -> left = Build(preorder,i,root-> val);
        root -> right= Build(preorder,i,UB);
        return root;
    }
};