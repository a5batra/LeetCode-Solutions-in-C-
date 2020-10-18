//
// Created by Ankit Batra on 10/18/20.
//

/* Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value.
 * So the median is the mean of the two middle value.
 * For example, [2,3,4], the median is 3 [2,3], the median is (2 + 3) / 2 = 2.5
 * Design a data structure that supports the following two operations:
 * void addNum(int num) - Add a integer number from the data stream to the data structure.
 * double findMedian() - Return the median of all elements so far. */

#include <iostream>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if (maxHeap.empty() || maxHeap.top() > num) {
            maxHeap.push(num);
        }
        else minHeap.push(num);

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        double median = 0.0;
        if (maxHeap.size() == minHeap.size()) {
            median = (maxHeap.top() + minHeap.top()) / 2.0;
            return median;
        }
        else if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(2);
    obj->addNum(3);
    double param_2 = obj->findMedian();
    std::cout << "Median is: " << param_2 << std::endl;

    obj->addNum(4);
    double param_3 = obj->findMedian();
    std::cout << "Median is: " << param_3 << std::endl;
    return 0;
}
