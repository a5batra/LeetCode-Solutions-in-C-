//
// Created by Ankit Batra on 1/28/21.
//

/* You are given an array of integers nums, there is a sliding window of size k which is moving from the
 * very left of the array to the very right. You can only see the k numbers in the window.
 * Each time the sliding window moves right by one position.
 * Return the max sliding window. */

#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nextGreater(n);
        vector<int> result;
        nextGreater[n - 1] = n;
        stack<int> s;
        s.push(n - 1);

        for (int i = n - 2; i >= 0; --i) {
            while (!s.empty() && nums[i] >= nums[s.top()]) s.pop();

            if (s.empty()) nextGreater[i] = n;
            else nextGreater[i] = s.top();

            s.push(i);
        }
        int j = 0;
        for (int i = 0; i < n - k + 1; ++i) {
            if (j < i) j = i;

            while (nextGreater[j] < i + k) j++;

            result.push_back(nums[j]);
        }

        return result;
    }
};

int main() {
    return 0;
}