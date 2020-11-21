//
// Created by Ankit Batra on 11/20/20.
//

// Given the root of a binary tree, return the inorder traversal of its nodes' values.

#include <iostream>
#include <vector>

using std::vector;

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
    vector<int> result;
    void inorderHelper(TreeNode* root) {
        if (root == nullptr) return;

        inorderHelper(root->left);
        result.push_back(root->val);
        inorderHelper(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return result;
        inorderHelper(root);

        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution obj;
    vector<int> result = obj.inorderTraversal(root);

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}

