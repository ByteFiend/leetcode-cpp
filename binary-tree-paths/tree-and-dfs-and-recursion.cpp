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
    void helper(TreeNode *root, string &path, vector<string> &ans) {
        if (nullptr == root) {
            return;
        }

        string newPath = path + "->" + to_string(root->val);
        if (nullptr == root->left && nullptr == root->right) {
            ans.push_back(newPath.substr(2));
            return;
        }

        helper(root->left, newPath, ans);
        helper(root->right, newPath, ans);
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        helper(root, path, ans);
        return ans;
    }
};