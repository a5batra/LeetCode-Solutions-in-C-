//
// Created by Ankit Batra on 7/9/20.
//

// Given a binary tree, return the sum of values of its deepest leaves.

#include <iostream>
#include <queue>

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
    static int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        if (root == nullptr) return sum;

        int currLevelSum = 0;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();
                currLevelSum += curr->val;
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            sum = currLevelSum;
            currLevelSum = 0;
        }
        return sum;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    std::cout << "Sum of values of deepest leaves: " << Solution::deepestLeavesSum(root) << std::endl;
    return 0;
}