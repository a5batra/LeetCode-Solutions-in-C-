//
// Created by Ankit Batra on 8/11/20.
//

/* Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
 * The binary search tree is guaranteed to have unique values. */

#include <iostream>

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
    int sum = 0;
public:
    void inorderTraversal(TreeNode* root, int L, int R) {
        if (root == nullptr) return;

        inorderTraversal(root->left, L, R);
        if (root->val >= L && root->val <= R)
            sum += root->val;
        inorderTraversal(root->right, L, R);

    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr) return 0;

        inorderTraversal(root, L, R);

        return sum;
    }
};

int main() {
    Solution obj;
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    std::cout << "Sum of all values between 7 and 15: " << obj.rangeSumBST(root, 7, 15) << std::endl;

    return 0;
}

