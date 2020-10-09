//
// Created by Ankit Batra on 10/8/20.
//

// Given a singly linked list, determine if it is a palindrome.

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
    static ListNode* reverseLinkedList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        ListNode* nextNode = head;

        while (currNode != nullptr) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
    static bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = slow->next;
        slow->next = reverseLinkedList(newHead);

        ListNode* reverseHead = slow->next;

        while (reverseHead != nullptr) {
            if (head->val != reverseHead->val) return false;
            head = head->next;
            reverseHead = reverseHead->next;
        }

        return true;

    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);

    std::cout << "Result: " << Solution::isPalindrome(head);
    return 0;
}

