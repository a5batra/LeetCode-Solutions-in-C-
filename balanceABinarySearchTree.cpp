//
// Created by Ankit Batra on 6/21/21.
//

/* Given a binary search tree, return a balanced binary search tree with the same node values.
 * A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ
 * by more than 1.
 * If there is more than one answer, return any of them. */

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
    vector<int> inorder;
public:
    void inorderTraversal(TreeNode* root) {
        if (!root) return;

        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }
    TreeNode* helper(vector<int>& inorder, int low, int high) {
        if (low > high) return nullptr;

        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = helper(inorder, low, mid - 1);
        root->right = helper(inorder, mid + 1, high);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return nullptr;

        inorderTraversal(root);

        return helper(inorder, 0, inorder.size() - 1);
    }
};

