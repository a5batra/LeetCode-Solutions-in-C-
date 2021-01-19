//
// Created by Ankit Batra on 1/18/21.
//

/* You have a queue of integers, you need to retrieve the first unique integer in the queue.
 * Implement the FirstUnique class:
 * FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
 * int showFirstUnique() returns the value of the first unique integer of the queue,
 * and returns -1 if there is no such integer.
 * void add(int value) insert value to the queue. */

#include <queue>
#include <unordered_map>
#include <vector>

using std::queue;
using std::unordered_map;
using std::vector;

class FirstUnique {
    unordered_map<int, int> count;
    queue<int> q;
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            q.push(num);
            count[num]++;
        }
    }

    int showFirstUnique() {
        while (!q.empty() && count[q.front()] > 1)
            q.pop();
        if (q.empty()) return -1;
        return q.front();
    }

    void add(int value) {
        count[value]++;
        if (count[value] == 1) q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

int main() {
    return 0;
}
