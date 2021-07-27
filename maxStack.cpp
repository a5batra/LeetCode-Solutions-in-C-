//
// Created by Ankit Batra on 7/26/21.
//

/* Design a max stack data structure that supports the stack operations and supports finding the stack's maximum
 * element.
 * Implement the MaxStack class:
 * MaxStack() Initializes the stack object.
 * void push(int x) Pushes element x onto the stack.
 * int pop() Removes the element on top of the stack and returns it.
 * int top() Gets the element on the top of the stack without removing it.
 * int peekMax() Retrieves the maximum element in the stack without removing it.
 * int popMax() Retrieves the maximum element in the stack and removes it.
 * If there is more than one maximum element, only remove the top-most one. */

class MaxStack {
    list<int> linkedList;
    map<int, vector<list<int>::iterator>> dict;
public:
    /** initialize your data structure here. */
    MaxStack() {

    }

    void push(int x) {
        linkedList.push_front(x);
        if (dict.count(x)) {
            dict[x].push_back(linkedList.begin());
        }
        else {
            dict[x] = {linkedList.begin()};
        }
    }

    int pop() {
        int val = linkedList.front();
        linkedList.pop_front();
        dict[val].pop_back();
        if (dict[val].empty()) dict.erase(val);
        return val;
    }

    int top() {
        return linkedList.front();
    }

    int peekMax() {
        return dict.rbegin()->first;
    }

    int popMax() {
        int maxVal = dict.rbegin()->first;
        auto it = dict[maxVal].back();
        linkedList.erase(it);
        dict[maxVal].pop_back();
        if (dict[maxVal].empty()) dict.erase(maxVal);

        return maxVal;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

