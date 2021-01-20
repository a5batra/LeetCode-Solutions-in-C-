//
// Created by Ankit Batra on 1/19/21.
//

/* Given a binary tree, return the zigzag level order traversal of its nodes' values.
 * (ie, from left to right, then right to left for the next level and alternate between). */

/* Given a binary tree, return the zigzag level order traversal of its nodes' values.
 * (ie, from left to right, then right to left for the next level and alternate between). */

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        bool lToR = true;

        vector<int> levelNodes;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();
                levelNodes.push_back(curr->val);
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            if (lToR) {
                lToR = false;
            }
            else {
                reverse(levelNodes.begin(), levelNodes.end());
                lToR = true;
            }
            result.push_back(levelNodes);
            levelNodes.clear();
        }
        return result;
    }
};

int main() {
    return 0;
}

