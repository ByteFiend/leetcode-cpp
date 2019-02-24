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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (nullptr == root) {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto size = q.size();

            vector<int> level;
            for (auto i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();

                level.push_back(cur->val);

                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};