//
// Created by Ankit Batra on 5/14/21.
//

// Definition for a Node.
/* class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    Node* head;
    Node* tail;
public:
    void dfs(Node* root) {
        if (!root) return;
        dfs(root->left);
        if (tail) {
            tail->right = root;
            root->left = tail;
        }
        else
            head = root;

        tail = root;
        dfs(root->right);

    }
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        dfs(root);

        head->left = tail;
        tail->right = head;

        return head;
    }
};

