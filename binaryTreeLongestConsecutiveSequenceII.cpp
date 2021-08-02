//
// Created by Ankit Batra on 7/29/21.
//

/* Given the root of a binary tree, return the length of the longest consecutive path in the tree.
 * This path can be either increasing or decreasing.
 * For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid.
 * On the other hand, the path can be in the child-Parent-child order,
 * where not necessarily be parent-child order. */

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
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        if (!root->left && !root->right) return {1, 1};

        int inc = 1, dec = 1;
        if (root->left) {
            pair<int, int> leftAns = dfs(root->left);
            if (root->val - 1 == root->left->val) {
                dec += leftAns.second;
            }
            else if (root->val + 1 == root->left->val) {
                inc += leftAns.first;
            }
        }

        if (root->right) {
            pair<int, int> rightAns = dfs(root->right);
            if (root->val - 1 == root->right->val) {
                dec = max(dec, 1 + rightAns.second);
            }
            else if (root->val + 1 == root->right->val) {
                inc = max(inc, 1 + rightAns.first);
            }
        }

        ans = max(ans, inc + dec - 1);

        return {inc, dec};
    }
    int longestConsecutive(TreeNode* root) {
        dfs(root);

        return ans;
    }
};

