//
// Created by Ankit Batra on 3/2/21.
//

/* You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it. */

#include <iostream>
#include <vector>

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
    static ListNode* merge(ListNode* l, ListNode* r) {
        if (l == nullptr && r == nullptr) return nullptr;
        if (l == nullptr || r == nullptr) {
            return l == nullptr ? r : l;
        }
        ListNode* head = l;
        ListNode* sortedPointer = head;
        if (l->val <= r->val) {
            sortedPointer = l;
            l = l->next;
        }
        else {
            sortedPointer = r;
            r = r->next;
        }

        head = sortedPointer;

        while (l != nullptr && r != nullptr) {
            if (l->val <= r->val) {
                sortedPointer->next = l;
                sortedPointer = sortedPointer->next;
                l = l->next;
            }
            else {
                sortedPointer->next = r;
                sortedPointer = sortedPointer->next;
                r = r->next;
            }
        }

        if (l == nullptr && r != nullptr) {
            sortedPointer->next = r;
        }
        else if (l != nullptr && r == nullptr) {
            sortedPointer->next = l;
        }

        return head;
    }
    static ListNode* helper(vector<ListNode*>& lists, int left, int right) {
        if (lists.size() == 0) return nullptr;

        if (left == right) return lists[left];

        int mid = left + (right - left) / 2;
        ListNode* l = helper(lists, left, mid);
        ListNode* r = helper(lists, mid + 1, right);

        return merge(l, r);
    }
    static ListNode* mergeKLists(vector<ListNode*>& lists) {

        return helper(lists, 0, lists.size() - 1);
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
