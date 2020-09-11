//
// Created by Ankit Batra on 9/10/20.
//

/* You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it. */

#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

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

        ListNode* temp  = head;
        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
    }
    static ListNode* mergedTwoSortedLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* sortedPointer = l1;
        if (l1->val <= l2->val) {
            sortedPointer = l1;
            l1 = l1->next;
        }
        else {
            sortedPointer = l2;
            l2 = l2->next;
        }

        ListNode* head = sortedPointer;

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

        if (l1 == nullptr && l2 != nullptr)
            sortedPointer->next = l2;
        if (l2 == nullptr && l1 != nullptr)
            sortedPointer->next = l1;

        return head;
    }
    static ListNode* mergeKLists(vector<ListNode*> lists) {
        int n = lists.size();
        if (n == 0) return nullptr;

        stack<ListNode*> s;
        s.push(lists[0]);

        for (int i = 1; i < n; ++i) {
            ListNode* stackTop = s.top();
            s.pop();
            ListNode* newHead = mergedTwoSortedLists(stackTop, lists[i]);
            s.push(newHead);
        }
        return s.top();
    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(6);

    vector<ListNode*> lists(3);
    lists[0] = head1;
    lists[1] = head2;
    lists[2] = head3;

    ListNode* head = Solution::mergeKLists(lists);
    Solution::printLinkedList(head);

}
