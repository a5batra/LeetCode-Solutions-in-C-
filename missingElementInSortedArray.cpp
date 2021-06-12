//
// Created by Ankit Batra on 6/11/21.
//

/* Given an integer array nums which is sorted in ascending order and all of its elements are unique and given
 * also an integer k, return the kth missing number starting from the leftmost number of the array. */

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> missingNums(n);

        for (int i = 1; i < n; ++i)
            missingNums[i] = nums[i] - nums[i - 1] - 1 + missingNums[i - 1];

        auto it = lower_bound(missingNums.begin(), missingNums.end(), k);
        int firstIdx = it - missingNums.begin();

        int ans = 0;
        ans = nums[firstIdx - 1] + k - missingNums[firstIdx - 1];

        return ans;
    }
};

