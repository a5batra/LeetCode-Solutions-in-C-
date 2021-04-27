//
// Created by Ankit Batra on 4/25/21.
//

/* Design an algorithm to encode an N-ary tree into a binary tree and decode the binary tree to get the original
 * N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children.
 * Similarly, a binary tree is a rooted tree in which each node has no more than 2 children.
 * There is no restriction on how your encode/decode algorithm should work.
 * You just need to ensure that an N-ary tree can be encoded to a binary tree and this binary tree can be decoded
 * to the original N-nary tree structure. */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

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
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) return nullptr;

        TreeNode* newRoot = new TreeNode(root->val);
        int sz = root->children.size();
        if (sz > 0) {
            newRoot->left = encode(root->children[0]);
            TreeNode* curr = newRoot->left;
            for (int i = 1; i < root->children.size(); ++i) {
                curr->right = encode(root->children[i]);
                curr = curr->right;
            }
        }
        return newRoot;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root) return nullptr;

        Node* newNode = new Node(root->val, vector<Node*>());
        TreeNode* curr = root->left;
        while (curr) {
            newNode->children.push_back(decode(curr));
            curr = curr->right;
        }

        return newNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));

