//
// Created by Ankit Batra on 4/28/21.
//

/* Given a root of an N-ary tree, you need to compute the length of the diameter of the tree.
 * The diameter of an N-ary tree is the length of the longest path between any two nodes in the tree.
 * This path may or may not pass through the root.
 * (Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value.) */

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
    int maxDia;
public:
    Solution() {
        maxDia = 0;
    }
    int height(Node* root) {
        if (!root) return 0;

        int prevMaxHeight = 0, currMaxHeight = 0;
        for (Node* child : root->children) {
            int cHeight = height(child);
            if (cHeight > currMaxHeight) {
                prevMaxHeight = currMaxHeight;
                currMaxHeight = cHeight;
            }
            else if (cHeight > prevMaxHeight) {
                prevMaxHeight = cHeight;
            }
        }

        maxDia = max(maxDia, prevMaxHeight + currMaxHeight);

        return 1 + currMaxHeight;
    }
    int diameter(Node* root) {
        if (!root) return 0;
        if (root->children.size() == 0) return 0;

        height(root);

        return maxDia;
    }
};

