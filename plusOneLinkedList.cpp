//
// Created by Ankit Batra on 5/28/21.
//

/* Given a non-negative integer represented as a linked list of digits, plus one to the integer.
 * The digits are stored such that the most significant digit is at the head of the list. */

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
    ListNode* reverseLinkedList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        ListNode* nextNode = head;

        while (currNode) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
    ListNode* plusOne(ListNode* head) {
        head = reverseLinkedList(head);
        int sum = 0, carry = 1;

        ListNode* temp = head;

        while (temp && carry) {
            sum = temp->val + carry;
            temp->val = sum % 10;
            carry = sum / 10;
            if (!temp->next && carry) {
                temp->next = new ListNode(carry);
                break;
            }
            temp = temp->next;
        }

        head = reverseLinkedList(head);

        return head;
    }
};

