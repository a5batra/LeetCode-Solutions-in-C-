//
// Created by Ankit Batra on 11/7/20.
//

/* Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one duplicate number in nums, return this duplicate number.
 * Follow-ups:
 * How can we prove that at least one duplicate number must exist in nums?
 * Can you solve the problem without modifying the array nums?
 * Can you solve the problem using only constant, O(1) extra space?
 * Can you solve the problem with runtime complexity less than O(n2)? */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) {
        nums.push_back(number);
    }

    std::cout << "Duplicate number is: " << Solution::findDuplicate(nums);
    return 0;
}