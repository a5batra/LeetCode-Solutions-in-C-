//
// Created by Ankit Batra on 6/15/20.
//

/*  Given the root node of a binary search tree (BST) and a value.
 * You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node.
 * If such node doesn't exist, you should return NULL. */

// Definition for a binary tree node.

#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    static TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return root;

        TreeNode* temp = root;
        while (temp != nullptr) {
            if (temp->val ==  val) return temp;
            else if (temp->val < val) temp = temp->right;
            else temp = temp->left;
        }
        return nullptr;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    int val;

    std::cout << "Enter the value to search: " << std::endl;
    std::cin >> val;

    std::cout << "Searched value is: " << Solution::searchBST(root, val)->val << std::endl;

}