//
// Created by Ankit Batra on 7/7/20.
//

/* Given a binary tree, return the bottom-up level order traversal of its nodes' values.
 * (ie, from left to right, level by level from leaf to root). */

#include <iostream>
#include <queue>
#include <vector>

using std::vector;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    static void printVector(vector<vector<int>>& levelOrder) {
        int n = levelOrder.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < levelOrder[i].size(); ++j)
                std::cout << levelOrder[i][j] << " ";
            std::cout << std::endl;
        }
    }
    static vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levelOrder;

        if (root == nullptr) return levelOrder;

        vector<int> levelNodes;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();
                levelNodes.push_back(curr->val);
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }
            levelOrder.push_back(levelNodes);
            levelNodes = {};
        }
        std::reverse(levelOrder.begin(), levelOrder.end());
        return levelOrder;
    }
};

int main() {
    vector<vector<int>> levelOrder;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    levelOrder = Solution::levelOrderBottom(root);
    Solution::printVector(levelOrder);

}


