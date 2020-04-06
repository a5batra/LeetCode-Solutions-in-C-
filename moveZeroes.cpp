//
// Created by Ankit Batra on 4/4/20.
//

/* Given an array nums, write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 *
 * Note:
 * 1. You must do this in-place without making a copy of the array.
 * 2. Minimize the total number of operations. */

#include <iostream>
#include <sstream>
#include <vector>

class Solution {
public:
    static void printArray(std::vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i)
            std::cout << nums[i] << " ";
    }
    static void moveZeroes(std::vector<int>& nums) {
        int len = nums.size();
        int idx = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] != 0) {
                nums[idx] = nums[i];
                idx++;
            }
        }
        for (int i = idx; i < len; ++i) {
            nums[i] = 0;
        }
    }
};

int main() {
    int number;
    std::string line;
    std::vector<int> nums;

    std::cout << "Enter the elements of array separated by space. " << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream(line);

    while(stream >> number)
        nums.push_back(number);

    std::cout << "The resulting array after moving all the 0's to the end: " << std::endl;
    Solution::moveZeroes(nums);
    Solution::printArray(nums);

    return 0;
}



