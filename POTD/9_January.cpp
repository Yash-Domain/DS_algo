/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q)
            return root;

        if (!root)
            return NULL;

        TreeNode* l = LCA(root->left, p, q);
        TreeNode* r = LCA(root->right, p, q);

        if (l && r) {
            return root;
        } else if (l) {
            return l;
        } else if (r) {
            return r;
        } else {
            return NULL;
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // step remain is find the deepest leaf node who are farthest 
        // that is p and q 
        // if p == null || q == null return not null 
        // else put p and q in LCA and get the answer 

        TreeNode* p = NULL;
        TreeNode* q = NULL;

        queue<TreeNode*>que;

        que.push(root);

        while(!que.empty()){
            int size = que.size();

            for(int i = 0 ; i < size ; i++){
                TreeNode* curr = que.front();
                que.pop();

                if(i == 0) p = curr;
                if(i == size-1) q = curr;

                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
        }

        if(p == NULL) return q;
        if(q == NULL) return p;

        return LCA(root,p,q);

    }
};