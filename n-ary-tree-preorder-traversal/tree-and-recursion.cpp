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
    vector<int> preorder(Node* root) {
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
            for (auto child = cur->children.rbegin(); child != cur->children.rend(); ++child) {
                if (nullptr == *child) {
                    continue;
                }
                s.push(*child);
            }
        }

        return ans;
    }
};