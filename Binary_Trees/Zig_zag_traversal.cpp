/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level(n);

            for(int i = 0 ; i < n ; i++){
            TreeNode* curr = q.front();
            q.pop();
            // this is level.push_back
            if(flag == true)
                level[i] = curr -> val;
            else level[n-i-1] = curr -> val;
            // this is insertion in queue 
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
            } 
            flag = !flag;
            ans.push_back(level);  
        }
        return ans;
    }
};
