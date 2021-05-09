//
// Created by Ankit Batra on 5/9/21.
//

/* Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and
 * nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
 * Return true if there is a 132 pattern in nums, otherwise, return false.
 * Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution? */

#include <vector>

using std::min;
using std::vector;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int currMin = nums[0];

        for (int j = 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (currMin < nums[k] && nums[k] < nums[j]) return true;
            }
            currMin = min(currMin, nums[j]);
        }

        return false;
    }
};

