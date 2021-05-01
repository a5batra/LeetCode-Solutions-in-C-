//
// Created by Ankit Batra on 5/1/21.
//

/* Given the roots of two binary search trees, root1 and root2, return true if and only if there is a node
 * in the first tree and a node in the second tree whose values sum up to a given integer target. */

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
    unordered_set<int> st;
public:
    void populateSet(TreeNode* root1) {
        if (!root1) return;
        st.insert(root1->val);
        populateSet(root1->left);
        populateSet(root1->right);
    }
    bool helper(TreeNode* root2, int target) {
        if (!root2) return false;
        if (st.count(target - root2->val)) {
            return true;
        }
        return helper(root2->left, target) || helper(root2->right, target);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        populateSet(root1);
        return helper(root2, target);
    }
};