//
// Created by Ankit Batra on 4/8/20.
//

/* Given a non-empty, singly linked list with head node head, return a middle node of linked list.
 * If there are two middle nodes, return the second middle node. */

#include <iostream>
#include <sstream>

using std::string;

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
        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
    }
    static ListNode* insert(ListNode* head, int val) {
        if (head == nullptr)
            head = new ListNode(val);
        else {
            ListNode* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = new ListNode(val);
        }
        return head;
    }
    static ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    int number;
    string line;
    ListNode* head = nullptr;
    ListNode* middle = nullptr;

    std::cout << "Enter the elements of the linked list separated by space. " << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream(line);

    while (stream >> number)
        head = Solution::insert(head, number);

    middle = Solution::middleNode(head);
    std::cout << "Middle node of the linked list: " << std::endl;
    Solution::printLinkedList(middle);

    return 0;
}

