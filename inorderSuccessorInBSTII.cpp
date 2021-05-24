//
// Created by Ankit Batra on 5/24/21.
//

/* Given a node in a binary search tree, return the in-order successor of that node in the BST.
 * If that node has no in-order successor, return null.
 * The successor of a node is the node with the smallest key greater than node.val.
 *
 * You will have direct access to the node but not to the root of the tree.
 * Each node will have a reference to its parent node. */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* findMin(Node* node) {
        if (!node) return nullptr;
        while (node->left)
            node = node->left;
        return node;
    }
    Node* inorderSuccessor(Node* node) {
        Node* successor = nullptr;

        if (node->right) return findMin(node->right);

        else {
            successor = node->parent;
            while (successor && successor->val < node->val) {
                node = successor;
                successor = node->parent;
            }
        }
        return successor;
    }
};

