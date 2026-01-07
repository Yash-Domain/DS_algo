class Solution {
public:
    long long max_ans = LLONG_MIN;
    int const mod = 1e9 +7;

    int sum_dfs(TreeNode* root) {
        if (!root)
            return 0;

        int sum = root->val;

        int ls = sum_dfs(root->left);
        int rs = sum_dfs(root->right);

        return sum + ls + rs;
    }

    long long compare_dfs(TreeNode* root, int total_Sum) {
        if (!root)
            return 0;

        long long ls = compare_dfs(root->left, total_Sum);
        long long rs = compare_dfs(root->right, total_Sum);

        int sum = root->val;
        long long subtree_sum = (sum + ls + rs);
        long long curr_ans = (subtree_sum) * (total_Sum - (subtree_sum));

        max_ans = max(max_ans, curr_ans);

        return (sum + ls + rs);
    }

    int maxProduct(TreeNode* root) {
        int total_Sum = sum_dfs(root);

        int a = compare_dfs(root, total_Sum);

        return max_ans % mod;
    }
};