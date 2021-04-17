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
        string data = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();
                if (!curr) data += "null,";
                else data += to_string(curr->val) + ',';
                if (curr) q.push(curr->left);
                if (curr) q.push(curr->right);
            }
        }
        data.pop_back();
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0 || data == "null") return nullptr;
        vector<string> arr;
        int idx = 0;
        string curr = "";
        while (idx < data.length()) {
            if (data[idx] == ',') {
                arr.push_back(curr);
                curr = "";
                idx++;
            }
            curr += data[idx];
            idx++;
        }

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(arr[0]));
        q.push(root);
        for (int i = 1; i < arr.size(); ++i) {
            TreeNode* curr = q.front();
            q.pop();
            if (arr[i] != "null") {
                TreeNode* left = new TreeNode(stoi(arr[i]));
                curr->left = left;
                q.push(left);
            }
            if (i < arr.size() - 1 && arr[++i] != "null") {
                TreeNode* right = new TreeNode(stoi(arr[i]));
                curr->right = right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));