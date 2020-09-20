//
// Created by Ankit Batra on 9/17/20.
//

/* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place and use only constant extra memory. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static void swap(vector<int>& nums, int idx, int swapIdx) {
        int temp = nums[idx];
        nums[idx] = nums[swapIdx];
        nums[swapIdx] = temp;
    }
    static void reverseVec(vector<int>& nums, int idx) {
        int n = nums.size();
        int i = idx;
        int j = n - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    static void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return;
        int idx = n - 2;

        while (idx >= 0 && nums[idx] >= nums[idx + 1])
            idx--;

        if (idx == -1) {
            reverseVec(nums, idx + 1);
            return;
        }

        int swapIdx = n - 1;
        while (swapIdx >= 0 && nums[idx] >= nums[swapIdx])
            swapIdx--;

        if (swapIdx == -1) return;

        swap(nums, idx, swapIdx);

        reverseVec(nums, idx + 1);

    }
};

int main() {
    int number;
    string line;
    vector<int> nums;

    std::cout << "Enter the permutation: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    Solution::nextPermutation(nums);

    for (int i = 0; i < nums.size(); ++i)
        std::cout << nums[i] << " ";

    return 0;

}

