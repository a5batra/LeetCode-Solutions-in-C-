//
// Created by Ankit Batra on 4/14/21.
//

/* The thief has found himself a new place for his thievery again.
 * There is only one entrance to this area, called the "root."
 * Besides the root, each house has one and only one parent house.
 * After a tour, the smart thief realized that "all houses in this place forms a binary tree".
 * It will automatically contact the police if two directly-linked houses were broken into on the same night.
 * Determine the maximum amount of money the thief can rob tonight without alerting the police. */

#include <iostream>
#include <map>

using std::max;
using std::map;

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
    map<pair<TreeNode*, bool>, int> maxRobAmt;
public:
    int dfs(TreeNode* root, bool parentRobbed) {
        if (!root) return 0;
        if (maxRobAmt.count(make_pair(root, parentRobbed)) > 0) return maxRobAmt[make_pair(root, parentRobbed)];
        int maxAmt = 0;
        if (parentRobbed) {
            // cannot rob current one
            maxAmt = max(maxAmt, dfs(root->left, false) + dfs(root->right, false));
        }
        else {
            // can rob or not rob
            maxAmt = max(maxAmt, max(root->val + dfs(root->left, true) + dfs(root->right, true), dfs(root->left, false) + dfs(root->right, false)));
        }

        return maxRobAmt[make_pair(root, parentRobbed)] = maxAmt;

    }
    int rob(TreeNode* root) {
        if (!root) return 0;

        return dfs(root, false);

    }
};