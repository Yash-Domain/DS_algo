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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int,map<int,multiset<int>>> mp ;  // VD , HD , Nodes present in it (vector type)
        queue<tuple<TreeNode*,int,int>> q ;   // Node , VD , HD
        q.push({root,0,0});

        while(!q.empty()){
            auto [curr, VD , HD] = q.front();
            q.pop();
            mp[VD][HD].insert(curr -> val); // mp[VD][HD] is now multiset
            if(curr -> left) q.push({curr -> left, VD -1 , HD + 1});
            if(curr -> right) q.push({curr -> right, VD +1 , HD + 1});
        }
        for(auto i : mp){
            vector<int> temp;
            for(auto k : i.second){
                temp.insert(temp.end(),k.second.begin(),k.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};