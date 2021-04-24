//
// Created by Ankit Batra on 4/24/21.
//


/* You are given all the nodes of an N-ary tree as an array of Node objects, where each node has a unique value.
 * Return the root of the N-ary tree. */

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
    Node* findRoot(vector<Node*> tree) {
        unordered_set<Node*> s;
        for (Node* n : tree) s.insert(n);

        for (Node* node : tree) {
            for (int i = 0; i < node->children.size(); ++i) {
                if (node->children[i]) {
                    s.erase(node->children[i]);
                }
            }
        }
        Node* root = *(begin(s));

        return root;
    }
};
