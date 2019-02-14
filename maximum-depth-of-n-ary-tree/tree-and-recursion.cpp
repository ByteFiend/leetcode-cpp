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
    int maxDepth(Node* root) {
        if (NULL == root) {
            return 0;
        }

        auto ans = 1;
        for (auto c : root->children) {
            ans = max(ans, maxDepth(c) + 1);
        }

        return ans;
    }
};