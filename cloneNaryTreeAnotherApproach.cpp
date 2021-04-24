//
// Created by Ankit Batra on 4/24/21.
//

/* Given a root of an N-ary tree, return a deep copy (clone) of the tree.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> clone;
public:
    void traverse(Node* root) {
        if (!root) return;

        int n = root->children.size();
        vector<Node*> child(n);
        clone[root] = new Node(root->val, child);

        for (int i = 0; i < n; ++i) {
            if (root->children[i]) traverse(root->children[i]);
        }

    }
    void helper(Node* root) {
        if (!root) return;

        int n = root->children.size();
        for (int i = 0; i < n; ++i) {
            if (root->children[i]) {
                clone[root]->children[i] = clone[root->children[i]];
                helper(root->children[i]);
            }
        }
    }
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;
        traverse(root);
        helper(root);

        return clone[root];
    }
};

