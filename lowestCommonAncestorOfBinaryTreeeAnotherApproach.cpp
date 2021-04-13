//
// Created by Ankit Batra on 4/12/21.
//

/* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * According to the definition of LCA on Wikipedia:
 * “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has
 * both p and q as descendants (where we allow a node to be a descendant of itself).” */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;
public:
    void dfs(TreeNode* root, TreeNode* pNode) {
        if (!root) return;
        parent[root] = pNode;
        dfs(root->left, root);
        dfs(root->right, root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent[root] = nullptr;
        dfs(root, nullptr);

        if (parent[p] == q) return q;
        if (parent[q] == p) return p;

        unordered_set<TreeNode*> qNodes;
        TreeNode* qParent = q;
        while (qParent != nullptr) {
            qNodes.insert(qParent);
            qParent = parent[qParent];
        }

        TreeNode* pParent = p;
        while (pParent != nullptr) {
            if (qNodes.count(pParent) > 0) return pParent;
            pParent = parent[pParent];
        }
        return nullptr;
    }
};

int main() {
    return 0;
}

