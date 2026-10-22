class Solution {
public:
    void dfs(TreeNode* node, int& sum) {
        if (node == nullptr) return;

        // Check if the left child is a leaf
        if (node->left != nullptr &&
            node->left->left == nullptr &&
            node->left->right == nullptr) {
            sum += node->left->val;
        }

        dfs(node->left, sum);
        dfs(node->right, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
};