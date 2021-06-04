//
// Created by Ankit Batra on 6/4/21.
//

/* A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge
 * connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass
 * through the root.
 * The path sum of a path is the sum of the node's values in the path.
 * Given the root of a binary tree, return the maximum path sum of any path. */

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
        ans = INT_MIN;
    }
    int helper(TreeNode* root) {
        if (!root) return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        int includeCurrNodeStraightPath = max(root->val, max(left, right) + root->val);
        int takeCurrNodeAsRoot = root->val + left + right;

        ans = max(ans, max(includeCurrNodeStraightPath, takeCurrNodeAsRoot));

        return includeCurrNodeStraightPath;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);

        return ans;
    }
};

