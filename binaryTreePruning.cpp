//
// Created by Ankit Batra on 7/23/21.
//

/* Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a
 * 1 has been removed.
 * A subtree of a node node is node plus every node that is a descendant of node. */

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
    bool dfs(TreeNode* root) {
        if (!root) return false;
        if (!root->left && !root->right) {
            if (root->val == 0) return false;
            else return true;
        }
        bool haveOneLeft = dfs(root->left);
        bool haveOneRight = dfs(root->right);
        if (!haveOneLeft) root->left = nullptr;
        if (!haveOneRight) root->right = nullptr;

        if (!haveOneLeft && !haveOneRight && root->val == 0)
            return false;

        return true;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool res = dfs(root);
        if (!res) return nullptr;
        return root;
    }
};

