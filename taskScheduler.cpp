//
// Created by Ankit Batra on 10/31/20.
//

/* Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different
 * task. Tasks could be done in any order. Each task is done in one unit of time.
 * For each unit of time, the CPU could complete either one task or just be idle.
 * However, there is a non-negative integer n that represents the cooldown period between two same tasks
 * (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
 * Return the least number of units of times that the CPU will take to finish all the given tasks. */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using std::priority_queue;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        int cycles = 0;

        for (char t : tasks)
            counts[t]++;

        priority_queue<int> maxHeap;
        for (auto c : counts)
            maxHeap.push(c.second);

        vector<int> temp;

        while (!maxHeap.empty()) {
            temp = {};
            for (int i = 0; i < n + 1; ++i) {
                if (!maxHeap.empty()) {
                    temp.push_back(maxHeap.top() - 1);
                    maxHeap.pop();
                }
            }
            for (int freq : temp) {
                if (freq != 0) maxHeap.push(freq);
            }
            cycles += maxHeap.empty() ? temp.size() : n + 1;
        }
        return cycles;
    }
};

int main() {
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    std::cout << "Number of cycles: " << Solution::leastInterval(tasks, n);
    return 0;
}
