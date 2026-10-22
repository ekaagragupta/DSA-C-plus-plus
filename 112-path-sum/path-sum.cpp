class Solution {
public:
    bool dfs(TreeNode* node, int sum, int targetSum) {
        if (node == nullptr) {
            return false;
        }

        sum += node->val;

        if (node->left == nullptr && node->right == nullptr) {
            return sum == targetSum;
        }

        return dfs(node->left, sum, targetSum) ||
               dfs(node->right, sum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};