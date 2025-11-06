// brute force 
class Solution {
public:
    vector<int>ans;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root -> left);
        ans.push_back(root -> val);
        inorder(root -> right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i = 1 ; i < ans.size() ; i++){
            if(ans[i] <= ans[i-1]) return false;
        }
        return true;
    }
};

// optimal using range wala concept 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MIN,LONG_MAX);
    }
    bool isValid(TreeNode* root , long val1 , long val2){
        if(!root) return true;
        if(root -> val <= val1 || root -> val >= val2) return false;
        return isValid(root->left,val1,root->val) && isValid(root->right,root->val,val2);
    }
};