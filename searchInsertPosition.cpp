//
// Created by Ankit Batra on 6/10/20.
//

/* Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

int main() {
    int number;
    string line;
    int target;
    vector<int> nums;

    std::cout << "Enter the elements of sorted array separated by space. " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Enter the target value. " << std::endl;
    std::cin >> target;

    std::cout << "The index where the target is found or is to be inserted: " << Solution::searchInsert(nums, target);

    return 0;
}
