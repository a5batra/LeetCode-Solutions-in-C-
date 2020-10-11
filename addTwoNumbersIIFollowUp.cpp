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
        std::cout <<std::endl;
    }
    static int calculateLen(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = calculateLen(l1);
        int len2 = calculateLen(l2);
        int sum = 0;
        int carry = 0;

        ListNode* l = new ListNode();
        ListNode* temp = l;

        if (len1 > len2) {
            while (len1 != len2) {
                temp->val = l1->val;
                temp->next = new ListNode();
                temp = temp->next;
                l1 = l1->next;
                len1--;
            }
        }
        else if (len2 > len1) {
            while (len1 != len2) {
                temp->val = l2->val;
                temp->next = new ListNode();
                temp = temp->next;
                l2 = l2->next;
                len2--;
            }
        }
        while (len1 != 0 && len2 != 0) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            temp->val = sum;
            len1--;
            len2--;
            if (len1 == 0) break;
            l1 = l1->next;
            l2 = l2->next;
            temp->next = new ListNode();
            temp = temp->next;
        }

        l = reverseLinkedList(l);

        printLinkedList(l);

        temp = l;
        while (temp != nullptr) {
            sum = temp->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            temp->val = sum;
            if (temp->next == nullptr && carry > 0) {
                temp->next = new ListNode(carry);
                break;
            }
            temp = temp->next;
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
