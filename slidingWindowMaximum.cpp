//
// Created by Ankit Batra on 10/29/20.
//

/* You are given an array of integers nums, there is a sliding window of size k which is moving from the
 * very left of the array to the very right.
 * You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * Return the max sliding window. */

#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

using std::deque;
using std::string;
using std::vector;

class Solution {
public:
    static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        if (n == 0) return result;
        deque<int> q;
        int i = 0;

        for (; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        for (; i < n; ++i) {
            result.push_back(nums[q.front()]);
            // remove the elements outside of current sliding window
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            // remove the elements which are not useful
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            // push current element to the queue
            q.push_back(i);
        }

        result.push_back(nums[q.front()]);

        return result;
    }
};

int main() {
    string line;
    int number;
    vector<int> nums;
    vector<int> result;
    int k;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Enter the value of k: " << std::endl;
    std::cin >> k;

    result = Solution::maxSlidingWindow(nums, k);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}


