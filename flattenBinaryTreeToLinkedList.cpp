//
// Created by Ankit Batra on 12/5/20.
//

// Given a binary tree, flatten it to a linked list in-place.

#include <iostream>
#include <stack>

using std::stack;

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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();

            if (curr->right != nullptr) s.push(curr->right);
            if (curr->left != nullptr) s.push(curr->left);

            if (s.empty()) {
                curr->right = s.top();
            }
            curr->left = nullptr;
        }
    }
};

int main() {
    return 0;
}