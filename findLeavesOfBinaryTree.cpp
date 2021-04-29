//
// Created by Ankit Batra on 4/28/21.
//

/* Given the root of a binary tree, collect a tree's nodes as if you were doing this:
 * Collect all the leaf nodes.
 * Remove all the leaf nodes.
 * Repeat until the tree is empty. */

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

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
    unordered_map<TreeNode*, int> height;
    int maxHeight;
public:
    Solution() {
        maxHeight = 0;
    }
    int dfs(TreeNode* root) {
        if (!root) return -1;
        if (!root->left && !root->right) return height[root] = 0;

        height[root] = 1 + max(dfs(root->left), dfs(root->right));

        maxHeight = max(maxHeight, height[root]);

        return height[root];
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root) return {};
        dfs(root);

        vector<vector<int>> leaves(maxHeight + 1, vector<int>());

        for (auto it : height) {
            int idx = it.second;
            leaves[idx].push_back(it.first->val);
        }
        return leaves;
    }
};

