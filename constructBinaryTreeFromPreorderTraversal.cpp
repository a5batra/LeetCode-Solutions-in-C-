//
// Created by Ankit Batra on 10/23/20.
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
public:
    static TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
        }
        else {
            TreeNode* curr = root;
            TreeNode* prev = nullptr;
            while (curr != nullptr) {
                if (curr->val < val) {
                    prev = curr;
                    curr = curr->right;
                }
                else {
                    prev = curr;
                    curr = curr->left;
                }
            }
            if (prev->val < val) {
                prev->right = new TreeNode(val);
            }
            else prev->left = new TreeNode(val);
        }
        return root;
    }
    static TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* root = nullptr;

        for (int i = 0; i < preorder.size(); ++i) {
            root = insert(root, preorder[i]);
        }
        return root;

    }
};

int main() {

    return 0;
}