//
// Created by Ankit Batra on 12/6/20.
//

/* You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
 * That means the first house is the neighbor of the last one.
 * Meanwhile, adjacent houses have a security system connected,
 * and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given a list of non-negative integers nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the police. */

#include <iostream>
#include <sstream>
#include <vector>

using std::max;
using std::string;
using std::vector;

class Solution {
public:
    static int rob(vector<int>& nums, int start, int end) {
        int prevTwo = 0, prevOne = 0, maxAmount = INT_MIN;

        for (int i = start; i <= end; ++i) {
            maxAmount = max(prevOne, prevTwo + nums[i]);
            prevTwo = prevOne;
            prevOne = maxAmount;
        }

        return maxAmount;
    }
    static int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));

    }
};

int main() {
    int number;
    string line;
    vector<int> nums;

    std::cout << "Enter the amounts as an array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) {
        nums.push_back(number);
    }

    std::cout << "Maximum amount that can be robbed: " << Solution::rob(nums);

    return 0;
}
