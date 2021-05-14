//
// Created by Ankit Batra on 5/10/21.
//

/* Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.
 * You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a
 * doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element,
 * and the successor of the last element is the first element.
 * We want to do the transformation in place. After the transformation, the left pointer of the tree node
 * should point to its predecessor, and the right pointer should point to its successor.
 * You should return the pointer to the smallest element of the linked list. */

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

#include <vector>

using std::vector;

class Solution {
    vector<int> inorder;
public:
    void dfs(Node* root) {
        if (!root) return;

        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        dfs(root);

        int n = inorder.size();

        Node* prev = nullptr;
        Node* head = new Node(inorder[0]);
        Node* curr = head;

        for (int i = 0; i < n - 1; ++i) {
            curr->left = prev;
            curr->right = new Node(inorder[i + 1]);
            prev = curr;
            curr = curr->right;
        }
        curr->left = prev;
        curr->right = head;
        head->left = curr;

        return head;

    }
};

