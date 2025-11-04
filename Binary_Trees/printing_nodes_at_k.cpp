/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void child_parent(TreeNode* root , unordered_map<TreeNode* , TreeNode*> &mp){
        if(!root) return;
        queue<TreeNode*> q ;
        q.push(root);
        while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr -> left) {
            q.push(curr -> left);
            mp[curr -> left] = curr ;
        }
        if(curr -> right){
            q.push(curr -> right);
            mp[curr -> right] = curr;
        }
    }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root) return ans;

        unordered_map<TreeNode*,TreeNode*> mp;
        child_parent(root,mp);

        queue<TreeNode*> q ;
        q.push(target);

        unordered_set<int>visited;
        visited.insert(target -> val);

        int level = 0;

        while(!q.empty()){
            int n = q.size();
            if(level == k) break;
            level++;
            for(int i = 0 ; i < n ; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left && !visited.count(curr -> left -> val)){
                    q.push(curr -> left);
                    visited.insert(curr -> left -> val);
                }
                if(curr -> right && !visited.count(curr -> right -> val)){
                    q.push(curr -> right);
                    visited.insert(curr -> right -> val);
                }
                if(mp[curr] && !visited.count(mp[curr] -> val)){
                    q.push(mp[curr]);
                    visited.insert(mp[curr] -> val);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }
        return ans;
    }
};