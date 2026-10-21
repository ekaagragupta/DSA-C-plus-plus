/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // ek answer list bana do
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        // queue list jisme level wise element nikal kr push pop hojaye
        queue<TreeNode*> q;

        // ek ek krke sabhi element bhejo queue meh
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            // level wise traversal kro
            vector<int> level;

            for (int i = 0; i < size; i++) {

                // jo queue meh dalo / enter krvao original tree mh se nikalne
                // ke liye
                TreeNode* node = q.front();

                // ab har ek node ko queue meh se analyse krne ke liye
                q.pop();

                // analyse
                level.push_back(node->val);

                if (node->left != NULL) {
                    q.push(node->left);
                }

                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            // aab level wise push kro final answer tree mh
            ans.push_back(level);
        }

        return ans;
    }
};