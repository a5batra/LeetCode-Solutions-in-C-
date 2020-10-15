//
// Created by Ankit Batra on 10/14/20.
//

/* Reverse a linked list from position m to n. Do it in one-pass.
 * Note: 1 ≤ m ≤ n ≤ length of list. */

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (m > 1) {
            prev = curr;
            curr = curr->next;
            m--;
            n--;
        }

        ListNode* conn = prev;
        ListNode* tail = curr;
        ListNode* nextNode = curr;

        while (n > 0) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            n--;
        }

        tail->next = curr;
        if (conn)
            conn->next = prev;
        else head = prev;

        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* newHead = nullptr;
    newHead = Solution::reverseBetween(head, 2, 4);

    ListNode* temp = head;

    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}
