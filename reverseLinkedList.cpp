//
// Created by Ankit Batra on 9/17/20.
//

// Reverse a singly linked list.

#include <iostream>


// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    static void printLinkedList(ListNode* head) {
        if (head == nullptr) return;
        ListNode* temp = head;

        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
    }
    static ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* currNext = head;

        while (curr != nullptr) {
            currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }
        return prev;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* reversedHead = Solution::reverseList(head);
    Solution::printLinkedList(reversedHead);

    return 0;
}

