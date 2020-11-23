//
// Created by Ankit Batra on 11/22/20.
//

/* Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that
 * adding up all the values along the path equals the given sum.
 * Note: A leaf is a node with no children. */

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
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr && sum - root->val == 0) return true;

        else return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);

    }
};

int main() {
    return 0;
}

