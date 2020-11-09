//
// Created by Ankit Batra on 11/8/20.
//

// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

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
    int i = 0;
    int kSmallest = 0;
public:
    void inorder(TreeNode* root, int k, int& i) {
        if (root == nullptr) return;
        inorder(root->left, k, i);
        i++;
        if (i == k) {
            kSmallest = root->val;
            return;
        }
        inorder(root->right, k, i);

    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k, i);
        return kSmallest;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution obj;
    int k;

    std::cout << "Enter the value of k: " << std::endl;
    std::cin >> k;

    std::cout << "kth Smallest Element: " << obj.kthSmallest(root, k);
    return 0;
}
