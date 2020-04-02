//
// Created by Ankit Batra on 4/1/20.
//

/* Given a non-empty array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? */

#include <iostream>
#include <sstream>
#include <vector>

class Solution {
public:
    static int singleNumber(std::vector<int>& nums) {
        int len = nums.size();
        int result = 0;
        for (int i = 0; i < len; ++i) {
            result ^= nums[i];
        }
        return result;
    }
};

int main() {
    int number, result = 0;
    std::string line;
    std::vector<int> nums;

    std::cout << "Enter the numbers separated by space: " << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream(line);

    while (stream >> number)
        nums.push_back(number);

    std::cout << "The single number is: " << Solution::singleNumber(nums);

    return 0;
}
