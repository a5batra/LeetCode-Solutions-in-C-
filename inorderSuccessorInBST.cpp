//
// Created by Ankit Batra on 5/24/21.
//

/* Given the root of a binary search tree and a node p in it, return the in-order successor of that node in the BST.
 * If the given node has no in-order successor in the tree, return null.
 * The successor of a node p is the node with the smallest key greater than p.val. */

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
    TreeNode* findMin(TreeNode* node) {
        if (!node) return nullptr;
        while (node->left)
            node = node->left;
        return node;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;

        if (p->right) return findMin(p->right);

        else {
            while (root) {
                if (p->val < root->val) {
                    successor = root;
                    root = root->left;
                }
                else if (p->val > root->val) root = root->right;
                else break;
            }
        }

        return successor;
    }
};

