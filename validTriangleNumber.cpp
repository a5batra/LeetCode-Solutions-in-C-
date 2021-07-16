//
// Created by Ankit Batra on 7/15/21.
//

/* Given an integer array nums, return the number of triplets chosen from the array that can make triangles
 * if we take them as side lengths of a triangle. */

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int count = 0;

        for (int i = 2; i < n; ++i) {
            left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    count += right - left;
                    right--;
                }
                else left++;
            }
        }

        return count;
    }
};

