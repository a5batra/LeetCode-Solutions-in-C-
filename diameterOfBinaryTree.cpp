//
// Created by Ankit Batra on 8/6/20.
//

/* Given a binary tree, you need to compute the length of the diameter of the tree.
 * The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
 * This path may or may not pass through the root. */

#include <iostream>

using std::pair;

// Definition for a binary tree node.
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
    static pair<int, int> heightDiameter(TreeNode* root) {
        if (root == nullptr) {
            pair<int, int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }
        pair<int, int> leftAnswer = heightDiameter(root->left);
        pair<int, int> rightAnswer = heightDiameter(root->right);
        int leftHeight = leftAnswer.first;
        int leftDiameter = leftAnswer.second;
        int rightHeight = rightAnswer.first;
        int rightDiameter = rightAnswer.second;

        int height = 1 + std::max(leftHeight, rightHeight);
        int diameter = std::max(leftHeight + rightHeight, std::max(leftDiameter, rightDiameter));
        pair<int, int> p;
        p.first = height;
        p.second = diameter;
        return p;

    }
    static int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        pair<int, int> p = heightDiameter(root);

        return p.second;
    }
};

int main() {
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->left->left->left->left = new TreeNode(8);
    root->left->right->right->right = new TreeNode(9);

    std::cout << "Diameter of this binary tree is: " << Solution::diameterOfBinaryTree(root) << std::endl;
}

