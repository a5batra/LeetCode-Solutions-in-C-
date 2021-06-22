//
// Created by Ankit Batra on 6/22/21.
//

/* Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and
 * postorder is the postorder traversal of the same tree, construct and return the binary tree. */

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
    unordered_map<int, int> dict;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            dict[inorder[i]] = i;
        }
        int pIdx = n - 1;
        return helper(inorder, 0, n - 1, postorder, pIdx);
    }

    TreeNode* helper(vector<int>& inorder, int low, int high, vector<int>& postorder, int& pIdx) {
        if (low > high || pIdx < 0) return nullptr;

        TreeNode* root = new TreeNode(postorder[pIdx]);
        int rootIdx = dict[root->val];
        pIdx--;
        root->right = helper(inorder, rootIdx + 1, high, postorder, pIdx);
        root->left = helper(inorder, low, rootIdx - 1, postorder, pIdx);

        return root;
    }
};

