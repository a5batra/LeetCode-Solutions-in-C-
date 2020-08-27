//
// Created by Ankit Batra on 8/26/20.
//

/* Given an array of integers that is already sorted in ascending order,
 * find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2.
 * Note:
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may not use the same element twice. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static void printVector(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            std::cout << nums[i] << " ";
        std::cout << std::endl;
    }
    static vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> indices(2);
        if (n == 0) return indices;

        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (numbers[i] + numbers[j] < target)
                ++i;
            else if(numbers[i] + numbers[j] > target)
                --j;
            else {
                indices[0] = i + 1;
                indices[1] = j + 1;
                break;
            }
        }
        return indices;
    }
};

int main() {
    int number;
    string line;
    int target;
    vector<int> nums;
    vector<int> indices;

    std::cout << "Enter the elements of array separated by space. " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Enter target value: " << std::endl;
    std::cin >> target;

    indices = Solution::twoSum(nums, target);
    std::cout << "Indices: " << std::endl;
    Solution::printVector(indices);

    return 0;
}
