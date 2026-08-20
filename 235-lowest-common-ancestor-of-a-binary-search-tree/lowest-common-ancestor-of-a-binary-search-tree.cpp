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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Look for keys in left and right subtrees
        TreeNode* leftLCA  = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // If both subtrees returned non-null, this node is the LCA
        if (leftLCA != nullptr && rightLCA != nullptr) {
            return root;
        }

        // Otherwise, return the non-null child
        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }
};