//
// Created by Ankit Batra on 1/7/21.
//

/* Given two non-empty binary trees s and t,
 * check whether tree t has exactly the same structure and node values with a subtree of s.
 * A subtree of s is a tree consists of a node in s and all of this node's descendants.
 * The tree s could also be considered as a subtree of itself. */

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
    static bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr) return false;
        else if (isSameTree(s, t)) return true;
        else return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    static bool isSameTree(TreeNode* s, TreeNode* t) {
        if (s == nullptr || t == nullptr) return s == nullptr && t == nullptr;

        return s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};

int main() {
    return 0;
}