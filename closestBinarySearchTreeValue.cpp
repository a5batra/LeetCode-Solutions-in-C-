//
// Created by Ankit Batra on 7/28/21.
//

/* Given the root of a binary search tree and a target value, return the value in the BST that is closest to the
 * target. */

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
    double diff;
    int ans;
public:
    Solution() {
        diff = DBL_MAX;
        ans = 0;
    }
    void dfs(TreeNode* root, double target) {
        if (!root) return;
        if (abs((double)root->val - target) < diff) {
            diff = abs((double)root->val - target);
            ans = root->val;
        }
        dfs(root->left, target);
        dfs(root->right, target);
    }
    int closestValue(TreeNode* root, double target) {
        dfs(root, target);

        return ans;
    }
};

