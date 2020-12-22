//
// Created by Ankit Batra on 12/21/20.
//

// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while (!q.empty()) {
            TreeNode* r1 = q.front();
            q.pop();
            TreeNode* r2 = q.front();
            q.pop();
            if (r1 == nullptr && r2 == nullptr) continue;
            if (r1 == nullptr || r2 == nullptr) return false;
            if (r1->val != r2->val) return false;
            q.push(r1->left);
            q.push(r2->right);
            q.push(r1->right);
            q.push(r2->left);
        }
        return true;
    }
};

int main() {
    return 0;
}