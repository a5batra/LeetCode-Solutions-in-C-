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
public:
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;

        vector<Node*> child(root->children.size());
        Node* cloneRoot = new Node(root->val, child);

        for (int i = 0; i < root->children.size(); ++i) {
            if (root->children[i]) {
                cloneRoot->children[i] = cloneTree(root->children[i]);
            }
        }

        return cloneRoot;
    }
};

