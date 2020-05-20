//
// Created by Ankit Batra on 5/19/20.
//

/* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n). */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int search(vector<int>& nums, int target) {
        int len = nums.size();

        if (len == 0) return -1;
        if (len == 1)
            return nums[0] == target ? 0 : -1;

        int low = 0;
        int mid = 0;
        int high = (len - 1);

        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    int number;
    int idx;
    int target;
    string line;
    vector<int> nums;

    std::cout << "Enter the elements of rotated sorted array: " << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream(line);

    while (stream >> number)
        nums.push_back(number);

    std::cout << "Enter the target value to search: " << std::endl;
    std::cin >> target;

    idx = Solution::search(nums, target);
    std::cout << "The target " << target << " is found at index: " << idx;

    return 0;
}
