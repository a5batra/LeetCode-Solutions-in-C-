//
// Created by Ankit Batra on 12/7/20.
//

/* The thief has found himself a new place for his thievery again.
 * There is only one entrance to this area, called the "root."
 * Besides the root, each house has one and only one parent house.
 * After a tour, the smart thief realized that "all houses in this place forms a binary tree".
 * It will automatically contact the police if two directly-linked houses were broken into on the same night.
 * Determine the maximum amount of money the thief can rob tonight without alerting the police. */

#include <iostream>
#include <unordered_map>

using std::max;
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
    unordered_map<TreeNode*, int> robMap;
    unordered_map<TreeNode*, int> notRobMap;
public:
    int dfs(TreeNode* root, bool parent_robbed) {
        if (root == nullptr) return 0;

        if (parent_robbed) {
            if (robMap.find(root) != robMap.end()) return robMap[root];

            return robMap[root] = dfs(root->left, false) + dfs(root->right, false);
        }
        else {
            // rob
            if (notRobMap.find(root) != notRobMap.end()) return notRobMap[root];
            int rob = root->val + dfs(root->left, true) + dfs(root->right, true);
            int notRob = dfs(root->left, false) + dfs(root->right, false);

            return notRobMap[root] = max(rob, notRob);
        }
    }
    int rob(TreeNode* root) {
        return dfs(root, false);
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(1);

    Solution obj;
    std::cout << "Result: " << obj.rob(root);

    return 0;
}
