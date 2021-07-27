//
// Created by Ankit Batra on 7/27/21.
//

/* Given an array nums of n integers and an integer target, find three integers in nums such that the sum is
 * closest to target. Return the sum of the three integers. You may assume that each input would have exactly one
 * solution. */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int prevAbsDiff = INT_MAX;
        int ans = 0;

        for (int i = 0; i < n - 2; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int absDiff = abs(target - nums[i] - nums[left] - nums[right]);
                if (absDiff < prevAbsDiff) {
                    prevAbsDiff = absDiff;
                    ans = nums[i] + nums[left] + nums[right];
                }
                int currDiff = target - nums[i] - nums[left] - nums[right];
                if (currDiff > 0) {
                    left++;
                }
                else if (currDiff < 0) {
                    right--;
                }
                else {
                    return target;
                }
            }
        }

        return ans;
    }
};

