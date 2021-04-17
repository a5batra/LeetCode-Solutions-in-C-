//
// Created by Ankit Batra on 4/17/21.
//

/* Serialization is the process of converting a data structure or object into a sequence of bits so that it can
 * be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed
 * later in the same or another computer environment.
 * Design an algorithm to serialize and deserialize a binary tree.
 * There is no restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized
 * to the original tree structure.
 *
 * Clarification: The input/output format is the same as how LeetCode serializes a binary tree.
 * You do not necessarily need to follow this format, so please be creative and come up with different
 * approaches yourself. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "null";
        string left = serialize(root->left);
        string right = serialize(root->right);

        return to_string(root->val) + ',' + left + ',' + right;
    }

    TreeNode* helper(queue<string>& nodes) {
        if (nodes.empty()) return nullptr;
        string val = nodes.front();
        nodes.pop();
        if (val == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = helper(nodes);
        root->right = helper(nodes);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        int idx = 0;
        string curr = "";
        while (idx < data.length()) {
            if (data[idx] == ',') {
                nodes.push(curr);
                curr = "";
                idx++;
            }
            curr += data[idx];
            idx++;
        }
        return helper(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

