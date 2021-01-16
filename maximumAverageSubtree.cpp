//
// Created by Ankit Batra on 1/16/21.
//

/* Given the root of a binary tree, find the maximum average value of any subtree of that tree.
 * (A subtree of a tree is any node of that tree plus all its descendants.
 * The average value of a tree is the sum of its values, divided by the number of nodes.) */

#include <iostream>

using std::pair;

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
    double maxAvg = 0.0;
public:
    pair<double, double> dfs(TreeNode* root) {
        if (root == nullptr) return {0,0};

        pair<double, double> p;
        p.first = root->val;
        p.second = 1;

        if (root->left != nullptr) {
            pair<double, double> resLeft = dfs(root->left);
            p.first += resLeft.first;
            p.second += resLeft.second;
        }
        if (root->right != nullptr) {
            pair<double , double > resRight = dfs(root->right);
            p.first += resRight.first;
            p.second += resRight.second;
        }

        if (p.first / p.second > maxAvg)
            maxAvg = p.first / p.second;

        return p;
    }
    double maximumAverageSubtree(TreeNode* root) {
        pair<int, int> p =  dfs(root);

        return maxAvg;
    }
};

