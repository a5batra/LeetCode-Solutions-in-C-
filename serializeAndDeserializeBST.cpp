//
// Created by Ankit Batra on 5/18/21.
//

/* Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a
 * file or memory buffer, or transmitted across a network connection link to be reconstructed later in the
 * same or another computer environment.
 * Design an algorithm to serialize and deserialize a binary search tree.
 * There is no restriction on how your serialization/deserialization algorithm should work.
 * You need to ensure that a binary search tree can be serialized to a string, and this string can be
 * deserialized to the original tree structure. The encoded string should be as compact as possible. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string>
#include <vector>

using std::string;
using std::vector;

class Codec {
    vector<string> preorder;
    TreeNode* root;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";

        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    vector<int> getPreorderArray(string data) {
        string s;
        istringstream stream(data);
        vector<int> arr;
        while (stream >> s) {
            if (s == "null")  continue;
            arr.push_back(stoi(s));
        }

        return arr;
    }
    TreeNode* helper(vector<int>& preorder, int& idx, int maxVal, int minVal) {
        if (idx >= preorder.size()) return nullptr;
        if (preorder[idx] >= maxVal || preorder[idx] <= minVal) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = helper(preorder, idx, root->val, minVal);
        root->right = helper(preorder, idx, maxVal, root->val);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preorder = getPreorderArray(data);
        int idx = 0;
        return helper(preorder, idx, INT_MAX, INT_MIN);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

