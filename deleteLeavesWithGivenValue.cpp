//
// Created by Ankit Batra on 5/27/21.
//

/* Given a binary tree root and an integer target, delete all the leaf nodes with value target.
 * Note that once you delete a leaf node with value target, if it's parent node becomes a leaf node and has the
 * value target, it should also be deleted (you need to continue doing that until you can't). */

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
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root->left) root->left =  removeLeafNodes(root->left, target);
        if (root->right) root->right = removeLeafNodes(root->right, target);
        return (!root->left && !root->right && root->val == target) ? nullptr : root;
    }
};

