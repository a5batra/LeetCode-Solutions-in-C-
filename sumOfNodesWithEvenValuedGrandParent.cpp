//
// Created by Ankit Batra on 5/11/21.
//

/* Given a binary tree, return the sum of values of nodes with even-valued grandparent.
 * (A grandparent of a node is the parent of its parent, if it exists.)
 * If there are no nodes with an even-valued grandparent, return 0. */

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
    int ans;
public:
    Solution() {
        ans = 0;
    }
    void dfs(TreeNode* node, TreeNode* par, TreeNode* grandPar) {
        if (!node) return;

        if (grandPar && grandPar->val % 2 == 0)
            ans += node->val;

        dfs(node->left, node, par);
        dfs(node->right, node, par);
    }
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) return ans;
        dfs(root, nullptr, nullptr);

        return ans;
    }
};

