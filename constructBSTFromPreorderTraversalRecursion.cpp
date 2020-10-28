//
// Created by Ankit Batra on 10/27/20.
//

/* Return the root node of a binary search tree that matches the given preorder traversal.
 * (Recall that a binary search tree is a binary tree where for every node,
 * any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.
 * Also recall that a preorder traversal displays the value of the node first, then traverses node.left,
 * then traverses node.right.)
 * It's guaranteed that for the given test cases there is always possible to find a binary search tree with the
 * given requirements. */

#include <iostream>
#include <vector>

using std::vector;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int idx = 0;
public:
    TreeNode* buildBSTHelper(vector<int>& preorder, int& idx, int minVal, int maxVal) {
        if (idx == preorder.size()) return nullptr;
        if (preorder[idx] <= minVal || preorder[idx] >= maxVal) return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = buildBSTHelper(preorder, idx, minVal, root->val);
        root->right = buildBSTHelper(preorder, idx, root->val, maxVal);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return nullptr;

        return buildBSTHelper(preorder, idx, INT_MIN, INT_MAX);
    }
};

int main() {

    return 0;
}