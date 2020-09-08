//
// Created by Ankit Batra on 9/8/20.
//

// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

#include <iostream>
#include <queue>

using std::queue;

class MovingAverage {
    int numElements = 0;
    double movingSum = 0.0;
    double movingAverage = 0.0;
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        numElements = size;
    }

    double next(int val) {
        if (q.size() < numElements) {
            movingSum += val;
            q.push(val);
            movingAverage = movingSum / q.size();
        }
        else {
            movingSum = movingSum - q.front() + val;
            q.pop();
            q.push(val);
            movingAverage = movingSum / q.size();
        }
        return movingAverage;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main() {
    MovingAverage* obj = new MovingAverage(3);
    double param_1 = obj->next(1);
    std::cout << "Moving Average: " << param_1 << std::endl;
    double param_2 = obj->next(10);
    std::cout << "Moving Average: " << param_2 << std::endl;
    double param_3 = obj->next(3);
    std::cout << "Moving Average: " << param_3 << std::endl;
    double param_4 = obj->next(5);
    std::cout << "Moving Average: " << param_4 << std::endl;

    return 0;
}