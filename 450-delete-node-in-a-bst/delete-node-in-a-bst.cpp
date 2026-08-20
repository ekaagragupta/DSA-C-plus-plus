class Solution {
public:

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;

        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    TreeNode* deleteNode(TreeNode* node, int key) {

        // Value not found
        if (node == nullptr) {
            return nullptr;
        }

        // Search in left subtree
        if (key < node->val) {
            node->left = deleteNode(node->left, key);
        }

        // Search in right subtree
        else if (key > node->val) {
            node->right = deleteNode(node->right, key);
        }

        // Node found
        else {

            // Case 1: No left child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: No right child
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            TreeNode* successor = minValueNode(node->right);

            node->val = successor->val;

            node->right = deleteNode(node->right, successor->val);
        }

        return node;
    }
};