//
// Created by Ankit Batra on 1/15/21.
//

/* We are given a binary tree (with root node root), a target node, and an integer value K.
 * Return a list of the values of all nodes that have a distance K from the target node.
 * The answer can be returned in any order. */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::queue;
using std::unordered_map;
using std::unordered_set;
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
    unordered_map<TreeNode*, TreeNode*> childToParent;
public:
    void dfs(TreeNode* child, TreeNode* parent) {
        if (child != nullptr) {
            childToParent[child] = parent;
            dfs(child->left, child);
            dfs(child->right, child);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> result;
        if (root == nullptr) return result;

        dfs(root, nullptr);

        queue<TreeNode*> q;
        q.push(target);
        int currLevel = 0;
        unordered_set<TreeNode*> visited;

        while (!q.empty()) {
            int sz = q.size();
            if (currLevel == K) break;
            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();
                visited.insert(curr);
                if (curr->left != nullptr && visited.find(curr->left) == visited.end())
                    q.push(curr->left);
                if (curr->right != nullptr && visited.find(curr->right) == visited.end())
                    q.push(curr->right);
                if (childToParent[curr] != nullptr && visited.find(childToParent[curr]) == visited.end())
                    q.push(childToParent[curr]);
            }
            currLevel++;
        }

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            result.push_back(curr->val);
        }

        return result;
    }
};

int main() {
    return 0;
}