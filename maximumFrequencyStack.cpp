//
// Created by Ankit Batra on 5/10/21.
//

/* Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.
 * Implement the FreqStack class:
 * FreqStack() constructs an empty frequency stack.
 * void push(int val) pushes an integer val onto the top of the stack.
 * int pop() removes and returns the most frequent element in the stack.
 * If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned. */

#include <unordered_map>
#include <vector>

using std::max;
using std::unordered_map;
using std::vector;

class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> freqSt;
    int maxFreq;
public:
    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        freq[val] += 1;
        maxFreq = max(maxFreq, freq[val]);
        if (freqSt.count(freq[val])) {
            freqSt[freq[val]].push_back(val);
        }
        else {
            freqSt[freq[val]] = {val};
        }
    }

    int pop() {
        int val = freqSt[maxFreq].back();
        freqSt[maxFreq].pop_back();
        if (freqSt[maxFreq].empty()) maxFreq--;
        freq[val] -= 1;

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

