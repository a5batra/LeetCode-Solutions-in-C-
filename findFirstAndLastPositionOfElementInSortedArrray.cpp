//
// Created by Ankit Batra on 11/22/20.
//

/* Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * If target is not found in the array, return [-1, -1].
 * Follow up: Could you write an algorithm with O(log n) runtime complexity? */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int binarySearch(vector<int>& nums, int target, string s) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        int result = -1;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result = mid;
                if (s == "first")
                    high = mid - 1;
                else low = mid + 1;
            }
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return result;
    }
    static vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> indices = {-1, -1};

        int first = binarySearch(nums, target, "first");
        int last = binarySearch(nums, target, "last");
        if (first == -1 || last == -1) return indices;

        indices[0] = first;
        indices[1] = last;

        return indices;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;
    int target;
    vector<int> indices;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) {
        nums.push_back(number);
    }

    std::cout << "Enter the target value: " << std::endl;
    std::cin >> target;

    indices = Solution::searchRange(nums, target);

    std::cout << "Result: " << std::endl;

    for (int i = 0; i < indices.size(); ++i) {
        std::cout << indices[i] << " " ;
    }
    return 0;
}

