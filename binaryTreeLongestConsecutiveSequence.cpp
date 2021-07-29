//
// Created by Ankit Batra on 7/29/21.
//

/* Given the root of a binary tree, return the length of the longest consecutive sequence path.
 * The path refers to any sequence of nodes from some starting node to any node in the tree along the
 * parent-child connections.
 * The longest consecutive path needs to be from parent to child (cannot be the reverse). */

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
        ans = 1;
    }
    void dfs(TreeNode* root, int parentVal, int currAns) {
        if (!root) return;
        if (root->val - parentVal == 1) {
            currAns++;
            ans = max(ans, currAns);
        }
        else
            currAns = 1;
        dfs(root->left, root->val, currAns);
        dfs(root->right, root->val, currAns);
    }
    int longestConsecutive(TreeNode* root) {
        dfs(root, -1e9, 1);

        return ans;
    }
};



