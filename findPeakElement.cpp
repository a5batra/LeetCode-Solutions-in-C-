//
// Created by Ankit Batra on 7/13/21.
//

/* A peak element is an element that is strictly greater than its neighbors.
 * Given an integer array nums, find a peak element, and return its index.
 * If the array contains multiple peaks, return the index to any of the peaks.
 * You may imagine that nums[-1] = nums[n] = -∞.
 * You must write an algorithm that runs in O(log n) time. */


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int mid = 0;

        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] < nums[mid + 1]) low = mid + 1;
            else high = mid;
        }

        return low;
    }
};