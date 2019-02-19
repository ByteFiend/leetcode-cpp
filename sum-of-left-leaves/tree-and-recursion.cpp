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
    int sumOfLeftLeaves(TreeNode* root) {
        if (nullptr == root || nullptr == root->left && nullptr == root->right) {
            return 0;
        }

        if (nullptr == root->left) {
            return sumOfLeftLeaves(root->right);
        }

        auto ans = 0;
        if (nullptr == root->left->left && nullptr == root->left->right) {
            ans += root->left->val;
        } else {
            ans += sumOfLeftLeaves(root->left);
        }

        ans += sumOfLeftLeaves(root->right);
        return ans;
    }
};