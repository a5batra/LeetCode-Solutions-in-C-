//
// Created by Ankit Batra on 8/4/20.
//

/* You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
 * the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and
 * it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given a list of non-negative integers representing the amount of money of each house,
 * determine the maximum amount of money you can rob tonight without alerting the police. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int maxAmount = INT_MIN;
        vector<int> dpTable(n);

        dpTable[0] = nums[0];
        dpTable[1] = std::max(nums[1], dpTable[0]);

        for (int i = 2; i < n; ++i) {
            dpTable[i] = std::max(dpTable[i-1], dpTable[i-2] + nums[i]);
        }

        maxAmount = dpTable[n - 1];

        return maxAmount;
    }
};

int main() {
    int number;
    string line;
    vector<int> arr;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        arr.push_back(number);

    std::cout << "Maximum money that can be robbed: " << Solution::rob(arr);
    return 0;
}