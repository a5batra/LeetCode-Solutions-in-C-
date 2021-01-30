//
// Created by ankitb on 1/30/21.
//

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
    int preIdx = 0;
    unordered_map<int, int> numToIdx;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;

        for (int i = 0; i < inorder.size(); ++i) {
            numToIdx[inorder[i]] = i;
        }

        return buildBSTHelper(preorder, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildBSTHelper(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if (start > end) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIdx++]);

        if (start == end) return root;

        int idx = numToIdx[root->val];

        root->left = buildBSTHelper(preorder, inorder, start, idx - 1);
        root->right = buildBSTHelper(preorder, inorder, idx + 1, end);

        return root;
    }
};