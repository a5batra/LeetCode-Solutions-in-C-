//
// Created by Ankit Batra on 11/3/20.
//
/* Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return true;

        int lastGoodIdxPos = n - 1;

        for (int i = n - 2; i >= 0; --i) {
            if (i + nums[i] >= lastGoodIdxPos) {
                lastGoodIdxPos = i;
            }
        }
        return lastGoodIdxPos == 0;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Result: " << Solution::canJump(nums);
    return 0;
}

