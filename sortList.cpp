//
// Created by Ankit Batra on 11/16/20.
//

/* Given the head of a linked list, return the list after sorting it in ascending order.
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)? */

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
    static ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* head = nullptr;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }

        ListNode* sortedPointer = head;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                sortedPointer->next = l1;
                sortedPointer = l1;
                l1 = l1->next;
            }
            else {
                sortedPointer->next = l2;
                sortedPointer = l2;
                l2 = l2->next;
            }
        }

        if (l1 == nullptr && l2 != nullptr) sortedPointer->next = l2;
        if (l2 == nullptr && l1 != nullptr) sortedPointer->next = l1;

        return head;
    }

    static ListNode* findMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    static ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* mid = findMiddle(head);
        ListNode* head2 = mid->next;
        mid->next = nullptr;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(head2);
        ListNode* mergedHead = mergeTwoSortedLists(l1, l2);

        return mergedHead;

    }
};

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    ListNode* newHead = Solution::sortList(head);

    ListNode* temp = newHead;

    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}

