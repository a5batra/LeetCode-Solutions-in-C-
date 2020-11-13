//
// Created by Ankit Batra on 11/13/20.
//

// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using  std::vector;

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
    static vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);


        while (!q.empty()) {
            int size = q.size();
            vector<int> levelNodes;
            while (size--) {
                TreeNode* currNode = q.front();
                q.pop();
                levelNodes.push_back(currNode->val);
                if (currNode->left != nullptr) q.push(currNode->left);
                if (currNode->right != nullptr) q.push(currNode->right);
            }
            result.push_back(levelNodes);
        }
        return result;
    }
};

int main() {
    vector<vector<int>> result;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    result = Solution::levelOrder(root);

    std::cout << "Level Order Traversal: " << std::endl;

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}