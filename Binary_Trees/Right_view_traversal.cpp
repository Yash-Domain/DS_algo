class Solution {
public:
    void traversal(TreeNode* root , int level ,vector<int> &ans ){
        if(!root) return;
        if(level == ans.size() ) ans.push_back(root -> val);
        traversal(root -> right , level + 1 , ans);
        traversal(root -> left , level + 1 , ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        traversal(root,0,ans);
        return ans;
    }
};