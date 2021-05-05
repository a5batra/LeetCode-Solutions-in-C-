//
// Created by Ankit Batra on 5/4/21.
//

/* Given an integer array nums, reorder it such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
 * You may assume the input array always has a valid answer. */

#include <vector>

using std::vector;

class Solution {
public:
    void swap(vector<int>& nums, int idx1, int idx2) {
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1 || n == 2) return;

        for (int i = 1; i < n - 1; i += 2) {
            swap(nums, i, i + 1);
        }

    }
};


