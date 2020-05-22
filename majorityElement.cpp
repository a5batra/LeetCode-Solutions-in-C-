//
// Created by Ankit Batra on 5/21/20.
//

/* Given an array of size n, find the majority element.
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array. */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> numToCount;

        for (int i = 0; i < n; ++i) {
            if (numToCount.find(nums[i]) != numToCount.end()) {
                numToCount[nums[i]] += 1;
                if (numToCount[nums[i]] > (n/2))
                    return nums[i];
            } else
                numToCount[nums[i]] = 1;
        }
        return -1;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;

    std::cout << "Enter the elements of array separated by space. " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "The majority element for the array is: " << Solution::majorityElement(nums);
    return 0;
}



