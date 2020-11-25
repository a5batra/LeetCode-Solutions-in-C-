//
// Created by Ankit Batra on 11/24/20.
//

/* You are given a binary tree in which each node contains an integer value.
 * Find the number of paths that sum to a given value.
 * The path does not need to start or end at the root or a leaf, but it must go downwards
 * (traveling only from parent nodes to child nodes).
 * The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000. */

#include <iostream>
#include <unordered_map>

using std::unordered_map;

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
    int numPaths = 0;
    int prefixSum = 0;
    unordered_map<int, int> sumToFreq;
public:
    void dfs(TreeNode* root, int sum) {
        if (root == nullptr) return;

        prefixSum += root->val;
        if (prefixSum == sum) numPaths++;

        int target = prefixSum - sum;
        if (sumToFreq.find(target) != sumToFreq.end()) numPaths += sumToFreq[target];
        if (sumToFreq.find(prefixSum) != sumToFreq.end()) sumToFreq[prefixSum] += 1;
        else sumToFreq[prefixSum] = 1;

        dfs(root->left, sum);
        dfs(root->right, sum);

        sumToFreq[prefixSum] -= 1;
        prefixSum -= root->val;
    }
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return numPaths;

        dfs(root, sum);

        return numPaths;
    }

};

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->right = new TreeNode(-3);
    root->right->right = new TreeNode(11);

    Solution obj;

    int numPaths = obj.pathSum(root, 8);

    std::cout << "Number of paths: " << numPaths << std::endl;

    return 0;
}

