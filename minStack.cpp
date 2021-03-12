//
// Created by Ankit Batra on 4/11/20.
//

/* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack. */

#include <iostream>
#include <vector>

class MinStack {
    vector<pair<int, int>> arr;
    int minVal;
public:
    /** initialize your data structure here. */
    MinStack() {
        minVal = INT_MAX;
    }

    void push(int x) {
        if (arr.size() == 0) {
            arr.push_back({x, x});
            return;
        }

        int minVal = arr[arr.size() - 1].second;
        arr.push_back({x, min(x, minVal)});
    }

    void pop() {
        arr.pop_back();
    }

    int top() {
        int t = arr[arr.size() - 1].first;
        return t;
    }

    int getMin() {
        int m = arr[arr.size() - 1].second;
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



