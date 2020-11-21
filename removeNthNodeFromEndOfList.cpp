//
// Created by Ankit Batra on 11/20/20.
//

/* Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * Follow up: Could you do this in one pass? */

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
     static ListNode* removeNthFromEnd(ListNode* head, int n) {
         if (head == nullptr) return head;

         ListNode* dummyNode = new ListNode(-1);
         dummyNode->next = head;
         ListNode* prevNode = head;
         ListNode* nextNode = head;

         int diff = 0;
         while (diff < n) {
             nextNode = nextNode->next;
             diff++;
         }

         while (nextNode->next != nullptr) {
             prevNode = prevNode->next;
             nextNode = nextNode->next;
         }

         prevNode->next = prevNode->next->next;

         if (prevNode == dummyNode) return prevNode->next;

         return head;
     }
 };

 int main() {
     ListNode* head = new ListNode(1);
     head->next = new ListNode(2);
     head->next->next = new ListNode(3);
     head->next->next->next = new ListNode(4);
     head->next->next->next->next = new ListNode(5);

     int n = 2;
     ListNode* newHead = Solution::removeNthFromEnd(head, n);

     ListNode* temp = newHead;
     while (temp != nullptr) {
         std::cout << temp->val << " ";
         temp = temp->next;
     }
     return 0;
 }