//
// Created by Ankit Batra on 11/27/20.
//

// Write a program to find the node at which the intersection of two singly linked lists begins.

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    static int findLen(ListNode* head) {
        int len = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        return len;

    }
    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        int lenA = findLen(headA);
        int lenB = findLen(headB);

        if (lenA > lenB) {
            ListNode* tempA = headA;
            while (lenA != lenB) {
                tempA = tempA->next;
                lenA--;
            }
            ListNode* tempB = headB;
            while (tempA != nullptr && tempB != nullptr) {
                if (tempA == tempB) return tempA;
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }

        else {
            ListNode* tempB = headB;
            while (lenA != lenB) {
                tempB = tempB->next;
                lenB--;
            }
            ListNode* tempA = headA;
            while (tempA != nullptr && tempB != nullptr) {
                if (tempA == tempB) return tempA;
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }
        return nullptr;
    }
};

int main() {

    return 0;
}