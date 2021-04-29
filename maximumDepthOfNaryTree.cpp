//
// Created by Ankit Batra on 4/29/21.
//

/* Given a n-ary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node. */

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
    int maxDepth(Node* root) {
        if (!root) return 0;

        int maxChildDepth = 0;
        for (Node* child : root->children) {
            maxChildDepth = max(maxChildDepth, maxDepth(child));
        }

        return 1 + maxChildDepth;
    }
};

