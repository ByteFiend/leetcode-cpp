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
        if (nullptr == root || nullptr == p || nullptr == q) {
            return nullptr;
        }
        if (p == q) {
            return p;
        }
        if (root == p || root == q) {
            return root;
        }

        auto left = lowestCommonAncestor(root->left, p, q), right = lowestCommonAncestor(root->right, p, q);
        if (nullptr == left) {
            return right;
        } else if (nullptr == right) {
            return left;
        } else {
            return root;
        }
    }
};