//
// Created by Ankit Batra on 10/10/20.
//

/* You are given two non-empty linked lists representing two non-negative integers.
 * The most significant digit comes first and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed. */

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
    static void printLinkedList(ListNode* head) {
        ListNode* temp = head;

        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverseLinkedList(l1);
        l2 = reverseLinkedList(l2);

        // Just for debugging
        printLinkedList(l1);
        printLinkedList(l2);

        int sum = 0;
        int carry = 0;

        ListNode* l = new ListNode();
        ListNode* temp = l;

        while (l1 != nullptr || l2 != nullptr) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            sum = sum % 10;
            temp->val = sum;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            if (l1 == nullptr && l2 == nullptr) break;
            temp->next = new ListNode();
            temp = temp->next;
        }

        if (carry > 0) {
            temp->next = new ListNode(carry);
        }

        l = reverseLinkedList(l);

        return l;
    }
};

int main() {
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* l = Solution::addTwoNumbers(l1, l2);

    std::cout << "After addition: " << std::endl;
    Solution::printLinkedList(l);

    return 0;
}

