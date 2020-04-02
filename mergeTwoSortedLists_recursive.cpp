//
// Created by Ankit Batra on 3/27/20.
//

/* Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together
 * the nodes of the first two lists. */

#include <iostream>
#include <sstream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static void printLinkedList(ListNode* head) {
        if (head == nullptr) return;
        ListNode* temp = head;
        while(temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
    }
    static ListNode* insert(ListNode* head, int val) {
        if (head == nullptr) {
            head = new ListNode(val);
        }
        else {
            ListNode* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = new ListNode(val);
        }
        return head;
    }
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;

        else if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main() {
    int number;
    std::string line;
    ListNode* head1 = nullptr;
    ListNode* head2 = nullptr;
    ListNode* head = nullptr;

    std::cout << "Enter the numbers of first sorted linked list." << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream1(line);

    while(stream1 >> number)
        head1 = Solution::insert(head1, number);

    std::cout << "Enter the numbers of second linked list." << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream2 (line);

    while(stream2 >> number)
        head2 = Solution::insert(head2, number);

    std::cout << "The new sorted list after splicing together the nodes of the two lists: " << std::endl;
    head = Solution::mergeTwoLists(head1, head2);
    Solution::printLinkedList(head);

    return 0;
}