//
// Created by Ankit Batra on 3/9/21.
//

// Given an unsorted integer array nums, find the smallest missing positive integer.

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) nums[i] = n + 1;
        }
        for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;
            if (idx >= n) continue;
            if (nums[idx] > 0) nums[idx] = -nums[idx];
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;

    std::cout << "Enter the array: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) nums.push_back(number);

    std::cout << "First Missing Positive: " << Solution::firstMissingPositive(nums);

    return 0;
}

