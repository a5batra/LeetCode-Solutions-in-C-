//
// Created by Ankit Batra on 5/29/21.
//

/* Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the
 * BST such that their sum is equal to the given target. */

#include <unordered_set>

using std::unordered_set;

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
    unordered_set<int> seen;
public:
    bool helper(TreeNode* root, int k) {
        if (!root) return false;
        if (seen.count(k - root->val)) return true;
        seen.insert(root->val);
        return helper(root->left, k) || helper(root->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        return helper(root, k);
    }
};

