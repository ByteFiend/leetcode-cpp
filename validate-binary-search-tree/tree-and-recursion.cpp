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
    bool helper(TreeNode *root, int minValue, int maxValue, bool minEnabled, bool maxEnabled) {
        if (nullptr == root) {
            return true;
        }

        if (minEnabled && root->val <= minValue || maxEnabled && root->val >= maxValue) {
            return false;
        }

        return helper(root->left, minValue, root->val, minEnabled, true) && helper(root->right, root->val, maxValue, true, maxEnabled);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, 0, 0, false, false);
    }
};