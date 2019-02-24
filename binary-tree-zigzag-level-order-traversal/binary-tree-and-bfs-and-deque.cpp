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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (nullptr == root) {
            return ans;
        }

        deque<TreeNode *> q;
        q.push_back(root);
        auto needReverse = false;
        TreeNode *cur;

        while (!q.empty()) {
            auto size = q.size();

            vector<int> level;
            for (auto i = 0; i < size; ++i) {
                if (needReverse) {
                    cur = q.back();
                    q.pop_back();

                    if (cur->right) {
                        q.push_front(cur->right);
                    }
                    if (cur->left) {
                        q.push_front(cur->left);
                    }
                } else {
                    cur = q.front();
                    q.pop_front();

                    if (cur->left) {
                        q.push_back(cur->left);
                    }
                    if (cur->right) {
                        q.push_back(cur->right);
                    }
                }
                level.push_back(cur->val);
            }

            ans.push_back(level);
            needReverse = !needReverse;
        }

        return ans;
    }
};