//
// Created by Ankit Batra on 9/24/20.
//

/* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
 * find the area of largest rectangle in the histogram. */

#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using std::max;
using std::stack;
using std::string;
using std::vector;

class Solution {
public:
    static int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stackOfIdx;
        int maxArea = 0;
        int top = 0;
        int i = 0;

        for (; i < n; ++i) {
            if (stackOfIdx.empty() || heights[i] >= heights[stackOfIdx.top()])
                stackOfIdx.push(i);
            else {
                while (!stackOfIdx.empty() && heights[stackOfIdx.top()] > heights[i]) {
                    top = stackOfIdx.top();
                    stackOfIdx.pop();
                    if (!stackOfIdx.empty()) maxArea = max(maxArea, heights[top] * (i - stackOfIdx.top() - 1));
                    else
                        maxArea = max(maxArea, heights[top] * i);
                }
                stackOfIdx.push(i);
            }
        }
        while (!stackOfIdx.empty()) {
            top = stackOfIdx.top();
            stackOfIdx.pop();
            if (!stackOfIdx.empty()) maxArea = max(maxArea, heights[top] * (i - stackOfIdx.top() - 1));
            else
                maxArea = max(maxArea, heights[top] * i);
        }
        return maxArea;
    }
};

int main() {
    int number;
    string line;
    vector<int> heights;

    std::cout << "Enter the heights of bars separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        heights.push_back(number);

    std::cout << "Largest Rectangle in Histogram: " << Solution::largestRectangleArea(heights);

    return 0;
}