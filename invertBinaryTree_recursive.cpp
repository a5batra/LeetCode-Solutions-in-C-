//
// Created by Ankit Batra on 6/1/20.
//

// Invert a binary tree.

#include <iostream>
#include <queue>

using std::queue;

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
    static void printBinaryTree(TreeNode* root) {
        if (root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            std::cout << curr->val << " ";
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }
    static TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;

        if (root->left != nullptr) root->left = invertTree(root->left);
        if (root->right != nullptr) root->right =  invertTree(root->right);

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->right->left = new TreeNode(6);

    root = Solution::invertTree(root);
    Solution::printBinaryTree(root);

    return 0;
}



