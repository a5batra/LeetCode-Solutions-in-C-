//
// Created by Ankit Batra on 2/28/20.
//
/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice. */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int len = nums.size();
        std::vector<int> indices(2);
        std::unordered_map<int, int> numToIdx;

        for(int i = 0; i < len; ++i) {
            if (numToIdx.find(target - nums[i]) != numToIdx.end()) {
                indices[0] = numToIdx[target - nums[i]];
                indices[1] = i;
            }
            else
                numToIdx[nums[i]] = i;
        }
        return indices;
    }

    static void printVector(std::vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; ++i)
            std::cout << nums[i] << " ";
        std::cout << std::endl;
    }
};

int main() {
    int number;
    int target;
    std::string line;
    std::vector<int> indices;
    std::vector<int> numbers;

    std::cout << "Enter the numbers separated by spaces: " << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    while (stream >> number)
        numbers.push_back(number);
    std::cout << "Enter the target value: " << std::endl;
    std::cin >> target;

    indices = Solution::twoSum(numbers, target);
    std::cout << "The indices whose value adds up to target: " << std::endl;
    Solution::printVector(indices);

    return 0;
}