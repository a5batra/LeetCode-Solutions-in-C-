//
// Created by ankitb on 2/1/21.
//

/* You have a queue of integers, you need to retrieve the first unique integer in the queue.
 * Implement the FirstUnique class:
 * FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
 * int showFirstUnique() returns the value of the first unique integer of the queue,
 * and returns -1 if there is no such integer.
 * void add(int value) insert value to the queue. */

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using std::list;
using std::unordered_map;
using std::vector;


class FirstUnique {
    unordered_map<int, list<int>::iterator> numToIter;
    unordered_map<int, int> count;
    list<int> linkedList;
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            if (count.find(num) != count.end()) {
                count[num] += 1;
                if (numToIter.find(num) != numToIter.end())
                    linkedList.erase(numToIter[num]);
                numToIter.erase(num);
            }
            else {
                count[num] = 1;
                linkedList.push_back(num);
                numToIter[num] = --linkedList.end();
            }
        }
    }

    int showFirstUnique() {
        if (linkedList.empty()) return -1;

        return linkedList.front();
    }

    void add(int value) {
        if (count.find(value) != count.end()) {
            count[value] += 1;
            if (numToIter.find(value) != numToIter.end()) {
                linkedList.erase(numToIter[value]);
                numToIter.erase(value);
            }
        }
        else {
            count[value] = 1;
            linkedList.push_back(value);
            numToIter[value] = --linkedList.end();
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */