//
// Created by Ankit Batra on 10/18/20.
//

/* A linked list is given such that each node contains an additional random pointer which could point to any node in
 * the list or null.
 * Return a deep copy of the list.
 * The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of
 * [val, random_index] where:
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null
 * if it does not point to any node. */

#include <iostream>
#include <unordered_map>

using std::unordered_map;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    static Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        unordered_map<Node*, Node*> map;

        Node* temp = head;
        while (temp != nullptr) {
            map[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr) {
            map[temp]->next = map[temp->next];
            map[temp]->random = map[temp->random];
            temp = temp->next;
        }
        return map[head];
    }
};

int main() {
    return 0;
}
