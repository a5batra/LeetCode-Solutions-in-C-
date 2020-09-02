//
// Created by Ankit Batra on 9/1/20.
//

/* You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself. */

#include <iostream>

//  Definition for singly-linked list.
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
        ListNode* temp = head;
        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
    }
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        int carry = 0;
        int sum = 0;
        ListNode* l = new ListNode();
        ListNode* temp = l;

        while (l1 != nullptr || l2 != nullptr) {
            temp->next = new ListNode();
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            sum = sum % 10;
            temp->val = sum;
            l1 = (l1 ? l1->next : nullptr);
            l2 = (l2 ? l2->next : nullptr);
            if (l1 == nullptr && l2 == nullptr) {
                temp->next = nullptr;
                break;
            }
            temp = temp->next;
        }

        if (carry != 0) {
            temp->next = new ListNode(carry);
        }

        return l;
    }
};

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* l = nullptr;

    l = Solution::addTwoNumbers(l1, l2);

    std::cout << "Linked list after adding: " << std::endl;
    Solution::printLinkedList(l);

    return 0;
}

