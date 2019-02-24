/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (nullptr == root) {
            return ans;
        }

        stack<Node *> s;
        s.push(root);

        while (!s.empty()) {
            auto cur = s.top();
            s.pop();

            ans.push_back(cur->val);
            for (auto child : cur->children) {
                if (nullptr == child) {
                    continue;
                }
                s.push(child);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};