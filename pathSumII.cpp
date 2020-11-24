//
// Created by Ankit Batra on 11/23/20.
//

/* Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 * Note: A leaf is a node with no children. */

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
    vector<vector<int>> result;
    vector<int> path;
    int pSum = 0;
public:
    void pathSumHelper(TreeNode* root, int sum) {
        if (root == nullptr) return;

        pSum += root->val;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && pSum == sum) {
            result.push_back(path);
        }
        pathSumHelper(root->left, sum);
        pathSumHelper(root->right, sum);
        path.pop_back();
        pSum -= root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return result;

        pathSumHelper(root, sum);
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution obj;
    vector<vector<int>> result = obj.pathSum(root, 22);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

