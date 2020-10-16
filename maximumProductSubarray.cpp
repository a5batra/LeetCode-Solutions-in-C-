//
// Created by Ankit Batra on 10/15/20.
//

/* Given an integer array nums, find the contiguous subarray within an array (containing at least one number)
 * which has the largest product. */

#include <iostream>
#include <sstream>
#include <vector>

using std::max;
using std::min;
using std::string;
using std::vector;

class Solution {
public:
    static int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return -1;

        int maxGlobal = nums[0];
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int temp = maxEndingHere;
            maxEndingHere = max(max(maxEndingHere * nums[i], minEndingHere * nums[i]), nums[i]);
            minEndingHere = min(min(temp * nums[i], minEndingHere * nums[i]), nums[i]);
            maxGlobal = max(maxEndingHere, maxGlobal);
        }

        return maxGlobal;
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

    std::cout << "Largest product: " << Solution::maxProduct(nums);

    return 0;
}

