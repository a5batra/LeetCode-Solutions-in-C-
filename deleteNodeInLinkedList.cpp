//
// Created by Ankit Batra on 6/2/20.
//

// Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

#include <iostream>
#include <sstream>

using std::string;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode* getNodeToDelete(ListNode* head, int val) {
        ListNode* temp = head;
        while(temp->val != val && temp->next != nullptr)
            temp = temp->next;

        return temp;
    }
    static void printLinkedList(ListNode* head) {
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
    static void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};

int main() {
    string line;
    int number;
    int val;
    ListNode* head = nullptr;
    ListNode* node = nullptr;

    std::cout << "Enter the elements of linked list separated by space. " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        head = Solution::insert(head, number);

    std::cout << "Enter the value in the node to be deleted. " << std::endl;
    std::cin >> val;

    node = Solution::getNodeToDelete(head, val);

    Solution::deleteNode(node);

    std::cout << "Linked list after deleting the node. " << std::endl;
    Solution::printLinkedList(head);

    return 0;
}