//
// Created by Ankit Batra on 7/22/21.
//

/* Given an array nums, partition it into two (contiguous) subarrays left and right so that:
 * Every element in left is less than or equal to every element in right.
 * left and right are non-empty.
 * left has the smallest possible size.
 * Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists. */

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftMax(n);
        leftMax[0] = nums[0];
        vector<int> rightMin(n);
        rightMin[n - 1] = nums[n - 1];

        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }

        for (int i = n - 2; i >= 0; --i) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (leftMax[i] <= rightMin[i + 1]) {
                ans = i + 1;
                break;
            }
        }

        return ans;


    }
};

