//
// Created by Ankit Batra on 10/24/20.
//

/* Given a binary tree, determine if it is a valid binary search tree (BST). Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees. */

#include <iostream>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    static bool isValidBSTHelper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (!root) return true;
        if ((min != nullptr && root->val <= min->val) || (max != nullptr && root->val >= max-> val)) return false;
        else return isValidBSTHelper(root->left, min, root) && isValidBSTHelper(root->right, root, max);
    }
    static bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, nullptr, nullptr);

    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    std::cout << "Result: " << Solution::isValidBST(root);

}

