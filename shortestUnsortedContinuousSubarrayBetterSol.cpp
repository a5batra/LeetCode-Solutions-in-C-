//
// Created by ankitb on 4/4/21.
//

/* Given an integer array nums, you need to find one continuous subarray that
 * if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.
 * Return the shortest such subarray and output its length. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxVal = nums[0];
        int minVal = nums[n - 1];
        int start = -1, end = -2;

        for (int i = 1; i < n; ++i) {
            maxVal = max(maxVal, nums[i]);
            if (nums[i] < maxVal) {
                end = i;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            minVal = min(minVal, nums[i]);
            if (nums[i] > minVal) {
                start = i;
            }
        }
        return end - start + 1;
    }
};

int main() {
    return 0;
}