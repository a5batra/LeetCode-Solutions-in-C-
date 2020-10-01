//
// Created by Ankit Batra on 9/29/20.
//

/* Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
 * You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right]
 * coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
 * Find the maximum coins you can collect by bursting the balloons wisely. */

#include <iostream>
#include <sstream>
#include <vector>

using std::max;
using std::string;
using std::vector;

class Solution {
public:
    static int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<vector<int>> dpTable(n, vector<int>(n));
        int left = 0, right = 0;

        for (int windowSize = 1; windowSize <= n; ++windowSize) {
            for (left = 0; left <= n - windowSize; ++left) {
                right = left + windowSize - 1;
                for (int i = left; i <= right; ++i) {
                    dpTable[left][right] = max(dpTable[left][right], (left == 0 ? 1 : nums[left - 1]) * nums[i] * (right == n - 1 ? 1 : nums[right + 1]) + (i - 1 < left ? 0 : dpTable[left][i - 1]) + (i + 1 > right ? 0 : dpTable[i + 1][right]));
                }
            }
        }

        return dpTable[0][n - 1];
    }
};

int main() {
    int number;
    vector<int> nums;
    string line;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Maximum number of coins: " << Solution::maxCoins(nums);

    return 0;
}

