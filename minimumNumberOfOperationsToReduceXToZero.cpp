//
// Created by Ankit Batra on 12/14/20.
//

/* You are given an integer array nums and an integer x. In one operation, you can either remove the
 * leftmost or the rightmost element from the array nums and subtract its value from x.
 * Note that this modifies the array for future operations.
 * Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1. */

#include <iostream>
#include <sstream>
#include <vector>

using std::max;
using std::string;
using std::vector;

class Solution {
public:
    static int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        if (n == 0) return 0;

        int total = 0, currSum = 0, maxLen = -1;
        int left = 0, right = 0;

        for (int num : nums) total += num;

        while (right < n) {
            currSum += nums[right];
            while (currSum > total - x && left <= right) {
                currSum -= nums[left];
                left++;
            }
            if (currSum == total - x) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen == -1 ? -1 : n - maxLen;
    }
};

int main() {
    int number, x;
    string line;
    vector<int> nums;

    std::cout << "Enter the elements of nums: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) nums.push_back(number);

    std::cout << "Enter the value of x: " << std::endl;
    std::cin >> x;

    std::cout << "Minimum number of operations: " << Solution::minOperations(nums, x);

    return 0;
}

