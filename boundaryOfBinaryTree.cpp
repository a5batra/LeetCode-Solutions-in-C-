//
// Created by Ankit Batra on 5/10/21.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/* The boundary of a binary tree is the concatenation of the root, the left boundary, the leaves ordered from
 * left-to-right, and the reverse order of the right boundary.
 * The left boundary is the set of nodes defined by the following:
 * The root node's left child is in the left boundary. If the root does not have a left child,
 * then the left boundary is empty.
 * If a node in the left boundary and has a left child, then the left child is in the left boundary.
 * If a node is in the left boundary, has no left child, but has a right child, then the right child is in the
 * left boundary.
 * The leftmost leaf is not in the left boundary.
 * The right boundary is similar to the left boundary, except it is the right side of the root's right subtree.
 * Again, the leaf is not part of the right boundary, and the right boundary is empty if the root does not have a
 * right child. The leaves are nodes that do not have any children. For this problem, the root is not a leaf.
 * Given the root of a binary tree, return the values of its boundary. */

#include <vector>

using std::vector;

class Solution {
    vector<int> ans;
    TreeNode* root;
public:
    void dfsLeft(TreeNode* node) {
        if (!node) return;
        if (!node->left && !node->right) return;

        ans.push_back(node->val);
        if (node->left) dfsLeft(node->left);
        else dfsLeft(node->right);
    }
    void dfsLeaves(TreeNode* node) {
        if (!node) return;

        dfsLeaves(node->left);
        if (node != root && !node->left && !node->right) ans.push_back(node->val);
        dfsLeaves(node->right);

    }
    void dfsRight(TreeNode* node) {
        if (!node) return;
        if (!node->left && !node->right) return;

        if (node->right) dfsRight(node->right);
        else dfsRight(node->left);

        ans.push_back(node->val);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return ans;

        this->root = root;
        ans.push_back(root->val);
        if (root->left) dfsLeft(root->left);
        dfsLeaves(root);
        if (root->right) dfsRight(root->right);

        return ans;
    }
};

