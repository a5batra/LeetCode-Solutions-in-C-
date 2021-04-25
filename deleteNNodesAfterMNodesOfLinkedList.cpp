//
// Created by Ankit Batra on 4/25/21.
//

/* Given the head of a linked list and two integers m and n. Traverse the linked list and remove some nodes in the
 * following way:
 * Start with the head as the current node.
 * Keep the first m nodes starting with the current node.
 * Remove the next n nodes
 * Keep repeating steps 2 and 3 until you reach the end of the list.
 * Return the head of the modified list after removing the mentioned nodes.
 * Follow up question: How can you solve this problem by modifying the list in-place? */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        if (!head) return nullptr;

        ListNode* curr = head;
        ListNode* temp = head;
        ListNode* newHead = head;

        while (temp != nullptr && curr != nullptr) {
            int keep = 0;
            while (keep < m - 1 && curr) {
                curr = curr->next;
                keep++;
            }
            int rem = 0;
            temp = curr;
            while (rem < n + 1 && temp) {
                temp = temp->next;
                rem++;
            }
            if (!curr) break;
            curr->next = temp;
            curr = curr->next;
        }

        return newHead;

    }
};

