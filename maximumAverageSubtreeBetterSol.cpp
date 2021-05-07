//
// Created by Ankit Batra on 5/7/21.
//

/* Given the root of a binary tree, find the maximum average value of any subtree of that tree.
 * (A subtree of a tree is any node of that tree plus all its descendants.
 * The average value of a tree is the sum of its values, divided by the number of nodes.) */

#include <iostream>

using std::pair;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    double maxAvg;
public:
    Solution() {
        maxAvg = 0.0;
    }
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        pair<int, int> p = {root->val + left.first + right.first, 1 + left.second + right.second};
        double currAvg = (double)p.first / p.second;
        if (currAvg > maxAvg) maxAvg = currAvg;

        return p;
    }
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);

        return maxAvg;
    }
};
