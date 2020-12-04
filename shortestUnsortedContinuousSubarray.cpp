//
// Created by Ankit Batra on 12/3/20.
//

/* Given an integer array nums, you need to find one continuous subarray that
 * if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.
 * Return the shortest such subarray and output its length. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int lowNum = INT_MAX, highNum = INT_MIN;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1])
                lowNum = std::min(lowNum, nums[i + 1]);
        }

        for (int i = n - 1; i > 0; --i) {
            if (nums[i] < nums[i - 1]) {
                highNum = std::max(highNum, nums[i - 1]);
            }
        }

        int left = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > lowNum) {
                left = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < highNum) {
                right = i;
                break;
            }
        }

        return right - left > 0 ? right - left + 1 : 0;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;

    std::cout << "Enter the elements of nums separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Result: " << Solution::findUnsortedSubarray(nums);

    return 0;
}

