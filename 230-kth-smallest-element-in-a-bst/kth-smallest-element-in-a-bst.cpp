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
     int count=0;
        int ans=0;
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        return ans;

    }
    private:
    void helper(TreeNode* root, int k) {
        if(root==nullptr) return ;

        helper(root->left,k);
        count++;

        if(count==k){
            ans=root->val;
            return;
        }
         if (count < k) {
            helper(root->right, k);
        }
    } 
};