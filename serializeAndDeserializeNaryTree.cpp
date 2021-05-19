//
// Created by Ankit Batra on 5/18/21.
//

/* Serialization is the process of converting a data structure or object into a sequence of bits so that it can be
 * stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node
 * has no more than N children. There is no restriction on how your serialization/deserialization algorithm should
 * work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be
 * deserialized to the original tree structure. */

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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "null,";
        string s = to_string(root->val) + ',';
        s += to_string(root->children.size()) + ',';
        for (Node* child : root->children) {
            s += serialize(child);
        }
        return s;
    }

    Node* dfs(queue<string>& q) {
        if (q.empty() || q.front() == "null") return nullptr;

        string rootVal = q.front();
        q.pop();
        int childSz = stoi(q.front());
        q.pop();
        Node* root = new Node(stoi(rootVal));
        for (int i = 0; i < childSz; ++i) {
            root->children.push_back(dfs(q));
        }

        return root;
    }
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        queue<string> q;
        size_t pos = 0;
        while ((pos = data.find(',')) != string::npos) {
            q.push(data.substr(0, pos));
            data.erase(0, pos + 1);
        }

        return dfs(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));