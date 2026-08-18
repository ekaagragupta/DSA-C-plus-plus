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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
       return insert(root,val);
        

    }

    private:
     TreeNode* insert(TreeNode* node, int data) {
    if (node == nullptr) {
        return new TreeNode(data);
    }

    if (data < node->val) {
        node->left = insert(node->left, data);
    }
    else if (data > node->val) {
        node->right = insert(node->right, data);
    }

    return node;
}
};