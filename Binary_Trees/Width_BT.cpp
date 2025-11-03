class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0 ;
        queue<pair<TreeNode*, long long>> q ;
        q.push({root , 0});
        int maxi = 0 ;
        while(!q.empty()){
            int n = q.size();
            int last , first;
            int mmin = q.front().second;
            for(int i = 0 ; i < n ; i++){
                auto [curr , level] = q.front();
                q.pop();
                level -= mmin;
                if(i == 0)  first = level;
                if(i == n-1)  last = level;
                
                if(curr -> left) q.push({curr -> left , 2*level+1});
                if(curr -> right) q.push({curr -> right , 2*level+2});
            }
            maxi = max(maxi , last - first + 1 );
        }
        return maxi;
    }
};