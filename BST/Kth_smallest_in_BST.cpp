class Solution {
public:
    //vector<int> ans;
    int cnt = 0;
    int ans=0;
    void inorder(TreeNode* root, int k){
        if(!root) return;
        inorder(root -> left,k);
        //ans.push_back(root -> val);
        cnt++;
        if(cnt==k) {
            ans = root -> val;
            return;
        }
        inorder(root -> right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        //return ans[k-1];
        return ans;
    }
};