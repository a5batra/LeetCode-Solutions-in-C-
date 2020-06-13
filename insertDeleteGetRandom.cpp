//
// Created by Ankit Batra on 6/12/20.
//

/* Design a data structure that supports all following operations in average O(1) time.
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned. */

#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class RandomizedSet {
    vector<int> nums;
    unordered_map<int,int> numToIdx;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (numToIdx.find(val) != numToIdx.end()) return false;
        else {
            numToIdx[val] = numToIdx.size();
            nums.push_back(val);
            return true;
        }
    }
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove (int val) {
        if (numToIdx.find(val) == numToIdx.end()) return false;
        else {
            int idx = numToIdx[val];
            nums[idx] = nums[nums.size() - 1];
            numToIdx[nums[nums.size() - 1]] = idx;
            nums.pop_back();
            numToIdx.erase(val);
            return true;
        }
    }
    /** Get a random element from the set. */
    int getRandom() {
        int n = std::rand() % nums.size();
        return nums[n];
    }
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->remove(2);
    int param_3 = obj->insert(2);
    bool param_4 = obj->getRandom();
    bool param_5 = obj->remove(1);
    bool param_6 = obj->insert(2);
    bool param_7 = obj->getRandom();

    std::cout << param_1 << " " << param_2 << " " << param_3 << " " << param_4 << " " <<  param_5 << " " << param_6 << " " << param_7 << std::endl;




}

